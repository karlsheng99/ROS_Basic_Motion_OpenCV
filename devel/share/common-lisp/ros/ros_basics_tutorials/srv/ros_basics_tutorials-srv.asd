
(cl:in-package :asdf)

(defsystem "ros_basics_tutorials-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Add2Ints" :depends-on ("_package_Add2Ints"))
    (:file "_package_Add2Ints" :depends-on ("_package"))
  ))