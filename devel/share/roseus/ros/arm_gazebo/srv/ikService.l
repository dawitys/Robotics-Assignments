;; Auto-generated. Do not edit!


(when (boundp 'arm_gazebo::ikService)
  (if (not (find-package "ARM_GAZEBO"))
    (make-package "ARM_GAZEBO"))
  (shadow 'ikService (find-package "ARM_GAZEBO")))
(unless (find-package "ARM_GAZEBO::IKSERVICE")
  (make-package "ARM_GAZEBO::IKSERVICE"))
(unless (find-package "ARM_GAZEBO::IKSERVICEREQUEST")
  (make-package "ARM_GAZEBO::IKSERVICEREQUEST"))
(unless (find-package "ARM_GAZEBO::IKSERVICERESPONSE")
  (make-package "ARM_GAZEBO::IKSERVICERESPONSE"))

(in-package "ROS")





(defclass arm_gazebo::ikServiceRequest
  :super ros::object
  :slots (_links _ee ))

(defmethod arm_gazebo::ikServiceRequest
  (:init
   (&key
    ((:links __links) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:ee __ee) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _links __links)
   (setq _ee __ee)
   self)
  (:links
   (&optional __links)
   (if __links (setq _links __links)) _links)
  (:ee
   (&optional __ee)
   (if __ee (setq _ee __ee)) _ee)
  (:serialization-length
   ()
   (+
    ;; float32[] _links
    (* 4    (length _links)) 4
    ;; float32[] _ee
    (* 4    (length _ee)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32[] _links
     (write-long (length _links) s)
     (dotimes (i (length _links))
       (sys::poke (elt _links i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[] _ee
     (write-long (length _ee) s)
     (dotimes (i (length _ee))
       (sys::poke (elt _ee i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32[] _links
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _links (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _links i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; float32[] _ee
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _ee (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _ee i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(defclass arm_gazebo::ikServiceResponse
  :super ros::object
  :slots (_angles ))

(defmethod arm_gazebo::ikServiceResponse
  (:init
   (&key
    ((:angles __angles) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _angles __angles)
   self)
  (:angles
   (&optional __angles)
   (if __angles (setq _angles __angles)) _angles)
  (:serialization-length
   ()
   (+
    ;; float64[] _angles
    (* 8    (length _angles)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64[] _angles
     (write-long (length _angles) s)
     (dotimes (i (length _angles))
       (sys::poke (elt _angles i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64[] _angles
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _angles (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _angles i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(defclass arm_gazebo::ikService
  :super ros::object
  :slots ())

(setf (get arm_gazebo::ikService :md5sum-) "739e17d373aedcc76ba2f276406c2579")
(setf (get arm_gazebo::ikService :datatype-) "arm_gazebo/ikService")
(setf (get arm_gazebo::ikService :request) arm_gazebo::ikServiceRequest)
(setf (get arm_gazebo::ikService :response) arm_gazebo::ikServiceResponse)

(defmethod arm_gazebo::ikServiceRequest
  (:response () (instance arm_gazebo::ikServiceResponse :init)))

(setf (get arm_gazebo::ikServiceRequest :md5sum-) "739e17d373aedcc76ba2f276406c2579")
(setf (get arm_gazebo::ikServiceRequest :datatype-) "arm_gazebo/ikServiceRequest")
(setf (get arm_gazebo::ikServiceRequest :definition-)
      "float32[] links
float32[] ee
---
float64[] angles

")

(setf (get arm_gazebo::ikServiceResponse :md5sum-) "739e17d373aedcc76ba2f276406c2579")
(setf (get arm_gazebo::ikServiceResponse :datatype-) "arm_gazebo/ikServiceResponse")
(setf (get arm_gazebo::ikServiceResponse :definition-)
      "float32[] links
float32[] ee
---
float64[] angles

")



(provide :arm_gazebo/ikService "739e17d373aedcc76ba2f276406c2579")


