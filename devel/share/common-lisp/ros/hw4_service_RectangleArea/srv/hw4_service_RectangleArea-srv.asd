
(cl:in-package :asdf)

(defsystem "hw4_service_RectangleArea-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "RectangleAreaService" :depends-on ("_package_RectangleAreaService"))
    (:file "_package_RectangleAreaService" :depends-on ("_package"))
  ))