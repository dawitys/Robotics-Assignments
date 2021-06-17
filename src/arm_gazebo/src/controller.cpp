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

			this->angleStateListener=arm_sub.subscribe("set_angles",1000, &ModelPush::publishContiniousAngle,this);

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
		void publishContiniousAngle(const arm_gazebo::Angles::ConstPtr& msg){
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
	public:
		void grip()
		{
			std::string phl = this->model->GetJoint("palm_hinge_left")->GetScopedName();
			this->model->GetJointController()->SetPositionTarget(phl, -45 * M_PI/ 180.0 );

			std::string lfh = this->model->GetJoint("left_finger_hinge")->GetScopedName();
			this->model->GetJointController()->SetPositionTarget(lfh, -45 * M_PI/ 180.0);

			std::string phr = this->model->GetJoint("palm_hinge_right")->GetScopedName();
			this->model->GetJointController()->SetPositionTarget(phr, 45 * M_PI/ 180.0 );

			std::string rfh = this->model->GetJoint("right_finger_hinge")->GetScopedName();
			this->model->GetJointController()->SetPositionTarget(rfh, 45 * M_PI/ 180.0);
		}

	public:
		void release()
		{
			std::string phl = this->model->GetJoint("palm_hinge_left")->GetScopedName();
			this->model->GetJointController()->SetPositionTarget(phl, 135 * M_PI/ 180.0);

			std::string lfh = this->model->GetJoint("left_finger_hinge")->GetScopedName();
			this->model->GetJointController()->SetPositionTarget(lfh, 135 * M_PI/ 180.0);

			std::string phr = this->model->GetJoint("palm_hinge_right")->GetScopedName();
			this->model->GetJointController()->SetPositionTarget(phr, -135 * M_PI/ 180.0);

			std::string rfh = this->model->GetJoint("right_finger_hinge")->GetScopedName();
			this->model->GetJointController()->SetPositionTarget(rfh, -135 * M_PI/ 180.0);
		}
	public:
		void updateJoint(std::vector<float> links, std::vector<float> ee)
		{
			ros::NodeHandle n;
			ros::ServiceClient client = n.serviceClient<arm_gazebo::IK>("client");

			arm_gazebo::IK srv;
			srv.request.links = links;
			srv.request.ee = ee;
			
			if (client.call(srv)){
				auto base = srv.response.angles[0]);
				this->SetAngle("base_hinge",base);
				auto arm1 = srv.response.angles[1]);
				this->SetAngle("arm1_hinge",arm1);
				auto arm2 = srv.response.angles[2]);
				this->SetAngle("arm2_hinge",arm2);
				auto arm3 = srv.response.angles[3]);
				this->SetAngle("arm3_hinge",arm3);
				auto arm4 = srv.response.angles[4]);
				this->SetAngle("arm4_hinge",arm4);
				auto grip = srv.response.angles[5]);
				this->SetAngle("gripRotation_hinge",grip);
			}
		}
	public:
		void gripperControllerconst arm_gazebo::gripper::ConstPtr& gripperCommand)
		{
			std::vector<float> links = { 0.1, 0.05, 2, 1, .5, .2, 0.05 }; 

			this->updateArmJointState( links, gripperCommand->ee);

			if( gripperCommand->catch ){
				this->catchObject();
			}else{
				this->releaseObject();
			}
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