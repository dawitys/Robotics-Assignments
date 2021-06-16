;; Auto-generated. Do not edit!


(when (boundp 'arm_gazebo::Angles)
  (if (not (find-package "ARM_GAZEBO"))
    (make-package "ARM_GAZEBO"))
  (shadow 'Angles (find-package "ARM_GAZEBO")))
(unless (find-package "ARM_GAZEBO::ANGLES")
  (make-package "ARM_GAZEBO::ANGLES"))

(in-package "ROS")
;;//! \htmlinclude Angles.msg.html


(defclass arm_gazebo::Angles
  :super ros::object
  :slots (_base_hinge _arm1_hinge _arm2_hinge _arm3_hinge ))

(defmethod arm_gazebo::Angles
  (:init
   (&key
    ((:base_hinge __base_hinge) 0.0)
    ((:arm1_hinge __arm1_hinge) 0.0)
    ((:arm2_hinge __arm2_hinge) 0.0)
    ((:arm3_hinge __arm3_hinge) 0.0)
    )
   (send-super :init)
   (setq _base_hinge (float __base_hinge))
   (setq _arm1_hinge (float __arm1_hinge))
   (setq _arm2_hinge (float __arm2_hinge))
   (setq _arm3_hinge (float __arm3_hinge))
   self)
  (:base_hinge
   (&optional __base_hinge)
   (if __base_hinge (setq _base_hinge __base_hinge)) _base_hinge)
  (:arm1_hinge
   (&optional __arm1_hinge)
   (if __arm1_hinge (setq _arm1_hinge __arm1_hinge)) _arm1_hinge)
  (:arm2_hinge
   (&optional __arm2_hinge)
   (if __arm2_hinge (setq _arm2_hinge __arm2_hinge)) _arm2_hinge)
  (:arm3_hinge
   (&optional __arm3_hinge)
   (if __arm3_hinge (setq _arm3_hinge __arm3_hinge)) _arm3_hinge)
  (:serialization-length
   ()
   (+
    ;; float32 _base_hinge
    4
    ;; float32 _arm1_hinge
    4
    ;; float32 _arm2_hinge
    4
    ;; float32 _arm3_hinge
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _base_hinge
       (sys::poke _base_hinge (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _arm1_hinge
       (sys::poke _arm1_hinge (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _arm2_hinge
       (sys::poke _arm2_hinge (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _arm3_hinge
       (sys::poke _arm3_hinge (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _base_hinge
     (setq _base_hinge (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _arm1_hinge
     (setq _arm1_hinge (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _arm2_hinge
     (setq _arm2_hinge (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _arm3_hinge
     (setq _arm3_hinge (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get arm_gazebo::Angles :md5sum-) "ebea2e1e660d8f6f3597c7be6738767c")
(setf (get arm_gazebo::Angles :datatype-) "arm_gazebo/Angles")
(setf (get arm_gazebo::Angles :definition-)
      "float32 base_hinge
float32 arm1_hinge
float32 arm2_hinge
float32 arm3_hinge
")



(provide :arm_gazebo/Angles "ebea2e1e660d8f6f3597c7be6738767c")


