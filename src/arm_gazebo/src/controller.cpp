#include <functional>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>
#include <iostream>
#include <ros/ros.h>
#include "std_msgs/String.h"
#include "arm_gazebo/Angles.h"

namespace gazebo
{
  class ModelPush : public ModelPlugin
  {
	private: float rad;

  	public:
		void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
		{
			if (!ros::isInitialized()){
				ROS_FATAL_STREAM("A ROS node for Gazebo has not been initialized, unable to load plugin. "
				<< "Load the Gazebo system plugin 'libgazebo_ros_api_plugin.so' in the gazebo_ros package)");
				return;
			}
			int argc=0;
			char **argv=NULL;
			ros::init(argc,argv,"AnglePublisherSubscriber");
			// set your PID values
			this->pid = common::PID(30.1, 10.01, 8.03);

			std::string base_hinge= this->model->GetJoint("base_hinge")->GetScopedName();
			std::string arm1_hinge = this->model->GetJoint("arm1_hinge")->GetScopedName();
			std::string arm2_hinge = this->model->GetJoint("arm2_hinge")->GetScopedName();
			std::string arm3_hinge = this->model->GetJoint("arm3_hinge")->GetScopedName();

			this->jointController->SetPositionPID(base_hinge, pid);
			this->jointController->SetPositionPID(arm1_hinge, pid);
			this->jointController->SetPositionPID(arm2_hinge, pid);
			this->jointController->SetPositionPID(arm3_hinge, pid);

			this->updateConnection = event::Events::ConnectWorldUpdateBegin(
			std::bind(&ModelPush::OnUpdate, this));
			ros::NodeHandle arm_pub,arm_sub,grip_sub;

			this->angleStatePublisher=arm_pub.advertise<std_msgs::String>("get_angles",1000);
			ros::Rate loop_rate(10);

			this->angleStateListener=arm_sub.subscribe("set_angles",1000, &ModelPush::publish,this);

			// ROS_INFO("Hello World!");
			//  ros::NodeHandle n;
			// ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

			this->model = _parent;
			this->jointController = this->model->GetJointController();


		}
	public:
		float changeToRad(float degree){
			rad=M_PI * degree / 180;
			return rad;
		}
	public:
		void publish(const arm_gazebo::Angles::ConstPtr& msg){
			this->model->GetJoints()[0]->SetPosition(0,changeToRad(msg->base_hinge));
			this->model->GetJoints()[1]->SetPosition(0,changeToRad(msg->arm1_hinge));
			this->model->GetJoints()[2]->SetPosition(0,changeToRad(msg->arm2_hinge));
			this->model->GetJoints()[3]->SetPosition(0,changeToRad(msg->arm3_hinge));
		}

    // Called by the world update start event
  public:
    void OnUpdate(){

			double base = physics::JointState(this->model->GetJoint("base_hinge")).Position(0);
			double arm1 = physics::JointState(this->model->GetJoint("arm1_hinge")).Position(0);
			double arm2 = physics::JointState(this->model->GetJoint("arm2_hinge")).Position(0);
			double arm3 = physics::JointState(this->model->GetJoint("arm3_hinge")).Position(0);

			std::cout << "base hinge value: " << base * 180.0 / M_PI << std::endl;
			std::cout << "arm1 hinge value: " << arm1 * 180.0 / M_PI << std::endl;
      		std::cout << "arm2 hinge value: " << arm2 * 180.0 / M_PI << std::endl;
      		std::cout << "arm3 hinge value: " << arm3 * 180.0 / M_PI << std::endl;
      		// Apply a small linear velocity to the model.
      		// this->model->SetLinearVel(ignition::math::Vector3d(0, vel, 0));
    }

  // Pointer to the model
  private:
    physics::ModelPtr model;

  private: 
  	ros::Publisher angleStatePublisher;

  private: 
    ros::Subscriber angleStateListener;
  // Pointer to the update event connection
  private:
  	event::ConnectionPtr updateConnection;
  // A joint controller object that takes PID value and apply angular velocity or sets position of the angles
  private:
  	physics::JointControllerPtr jointController;
  // PID object
  private:
	common::PID pid;
  };


  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(ModelPush)
}