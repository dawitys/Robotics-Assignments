;; Auto-generated. Do not edit!


(when (boundp 'arm_gazebo::fkService)
  (if (not (find-package "ARM_GAZEBO"))
    (make-package "ARM_GAZEBO"))
  (shadow 'fkService (find-package "ARM_GAZEBO")))
(unless (find-package "ARM_GAZEBO::FKSERVICE")
  (make-package "ARM_GAZEBO::FKSERVICE"))
(unless (find-package "ARM_GAZEBO::FKSERVICEREQUEST")
  (make-package "ARM_GAZEBO::FKSERVICEREQUEST"))
(unless (find-package "ARM_GAZEBO::FKSERVICERESPONSE")
  (make-package "ARM_GAZEBO::FKSERVICERESPONSE"))

(in-package "ROS")





(defclass arm_gazebo::fkServiceRequest
  :super ros::object
  :slots (_angles _links ))

(defmethod arm_gazebo::fkServiceRequest
  (:init
   (&key
    ((:angles __angles) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:links __links) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _angles __angles)
   (setq _links __links)
   self)
  (:angles
   (&optional __angles)
   (if __angles (setq _angles __angles)) _angles)
  (:links
   (&optional __links)
   (if __links (setq _links __links)) _links)
  (:serialization-length
   ()
   (+
    ;; float64[] _angles
    (* 8    (length _angles)) 4
    ;; float64[] _links
    (* 8    (length _links)) 4
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
     ;; float64[] _links
     (write-long (length _links) s)
     (dotimes (i (length _links))
       (sys::poke (elt _links i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
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
   ;; float64[] _links
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _links (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _links i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(defclass arm_gazebo::fkServiceResponse
  :super ros::object
  :slots (_ee ))

(defmethod arm_gazebo::fkServiceResponse
  (:init
   (&key
    ((:ee __ee) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _ee __ee)
   self)
  (:ee
   (&optional __ee)
   (if __ee (setq _ee __ee)) _ee)
  (:serialization-length
   ()
   (+
    ;; float64[] _ee
    (* 8    (length _ee)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64[] _ee
     (write-long (length _ee) s)
     (dotimes (i (length _ee))
       (sys::poke (elt _ee i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64[] _ee
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _ee (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _ee i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(defclass arm_gazebo::fkService
  :super ros::object
  :slots ())

(setf (get arm_gazebo::fkService :md5sum-) "7064256d7c8bd8994ec62c2cfe279a6e")
(setf (get arm_gazebo::fkService :datatype-) "arm_gazebo/fkService")
(setf (get arm_gazebo::fkService :request) arm_gazebo::fkServiceRequest)
(setf (get arm_gazebo::fkService :response) arm_gazebo::fkServiceResponse)

(defmethod arm_gazebo::fkServiceRequest
  (:response () (instance arm_gazebo::fkServiceResponse :init)))

(setf (get arm_gazebo::fkServiceRequest :md5sum-) "7064256d7c8bd8994ec62c2cfe279a6e")
(setf (get arm_gazebo::fkServiceRequest :datatype-) "arm_gazebo/fkServiceRequest")
(setf (get arm_gazebo::fkServiceRequest :definition-)
      "float64[] angles
float64[] links
---
float64[] ee
")

(setf (get arm_gazebo::fkServiceResponse :md5sum-) "7064256d7c8bd8994ec62c2cfe279a6e")
(setf (get arm_gazebo::fkServiceResponse :datatype-) "arm_gazebo/fkServiceResponse")
(setf (get arm_gazebo::fkServiceResponse :definition-)
      "float64[] angles
float64[] links
---
float64[] ee
")



(provide :arm_gazebo/fkService "7064256d7c8bd8994ec62c2cfe279a6e")


