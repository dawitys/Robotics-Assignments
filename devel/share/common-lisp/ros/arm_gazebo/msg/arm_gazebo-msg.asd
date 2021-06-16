
(cl:in-package :asdf)

(defsystem "arm_gazebo-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Angles" :depends-on ("_package_Angles"))
    (:file "_package_Angles" :depends-on ("_package"))
  ))