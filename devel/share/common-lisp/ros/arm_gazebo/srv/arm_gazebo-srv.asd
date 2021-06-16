
(cl:in-package :asdf)

(defsystem "arm_gazebo-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "fkService" :depends-on ("_package_fkService"))
    (:file "_package_fkService" :depends-on ("_package"))
    (:file "ikService" :depends-on ("_package_ikService"))
    (:file "_package_ikService" :depends-on ("_package"))
  ))