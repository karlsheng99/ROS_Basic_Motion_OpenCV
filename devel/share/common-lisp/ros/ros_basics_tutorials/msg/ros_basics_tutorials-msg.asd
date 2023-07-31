
(cl:in-package :asdf)

(defsystem "ros_basics_tutorials-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "IoTmsg" :depends-on ("_package_IoTmsg"))
    (:file "_package_IoTmsg" :depends-on ("_package"))
  ))