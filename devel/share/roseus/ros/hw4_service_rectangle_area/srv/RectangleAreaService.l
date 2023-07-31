;; Auto-generated. Do not edit!


(when (boundp 'hw4_service_rectangle_area::RectangleAreaService)
  (if (not (find-package "HW4_SERVICE_RECTANGLE_AREA"))
    (make-package "HW4_SERVICE_RECTANGLE_AREA"))
  (shadow 'RectangleAreaService (find-package "HW4_SERVICE_RECTANGLE_AREA")))
(unless (find-package "HW4_SERVICE_RECTANGLE_AREA::RECTANGLEAREASERVICE")
  (make-package "HW4_SERVICE_RECTANGLE_AREA::RECTANGLEAREASERVICE"))
(unless (find-package "HW4_SERVICE_RECTANGLE_AREA::RECTANGLEAREASERVICEREQUEST")
  (make-package "HW4_SERVICE_RECTANGLE_AREA::RECTANGLEAREASERVICEREQUEST"))
(unless (find-package "HW4_SERVICE_RECTANGLE_AREA::RECTANGLEAREASERVICERESPONSE")
  (make-package "HW4_SERVICE_RECTANGLE_AREA::RECTANGLEAREASERVICERESPONSE"))

(in-package "ROS")





(defclass hw4_service_rectangle_area::RectangleAreaServiceRequest
  :super ros::object
  :slots (_width _height ))

(defmethod hw4_service_rectangle_area::RectangleAreaServiceRequest
  (:init
   (&key
    ((:width __width) 0.0)
    ((:height __height) 0.0)
    )
   (send-super :init)
   (setq _width (float __width))
   (setq _height (float __height))
   self)
  (:width
   (&optional __width)
   (if __width (setq _width __width)) _width)
  (:height
   (&optional __height)
   (if __height (setq _height __height)) _height)
  (:serialization-length
   ()
   (+
    ;; float32 _width
    4
    ;; float32 _height
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _width
       (sys::poke _width (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _height
       (sys::poke _height (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _width
     (setq _width (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _height
     (setq _height (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass hw4_service_rectangle_area::RectangleAreaServiceResponse
  :super ros::object
  :slots (_area ))

(defmethod hw4_service_rectangle_area::RectangleAreaServiceResponse
  (:init
   (&key
    ((:area __area) 0.0)
    )
   (send-super :init)
   (setq _area (float __area))
   self)
  (:area
   (&optional __area)
   (if __area (setq _area __area)) _area)
  (:serialization-length
   ()
   (+
    ;; float32 _area
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _area
       (sys::poke _area (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _area
     (setq _area (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass hw4_service_rectangle_area::RectangleAreaService
  :super ros::object
  :slots ())

(setf (get hw4_service_rectangle_area::RectangleAreaService :md5sum-) "92e9c8f940da77dc3e1bc289f7dd146e")
(setf (get hw4_service_rectangle_area::RectangleAreaService :datatype-) "hw4_service_rectangle_area/RectangleAreaService")
(setf (get hw4_service_rectangle_area::RectangleAreaService :request) hw4_service_rectangle_area::RectangleAreaServiceRequest)
(setf (get hw4_service_rectangle_area::RectangleAreaService :response) hw4_service_rectangle_area::RectangleAreaServiceResponse)

(defmethod hw4_service_rectangle_area::RectangleAreaServiceRequest
  (:response () (instance hw4_service_rectangle_area::RectangleAreaServiceResponse :init)))

(setf (get hw4_service_rectangle_area::RectangleAreaServiceRequest :md5sum-) "92e9c8f940da77dc3e1bc289f7dd146e")
(setf (get hw4_service_rectangle_area::RectangleAreaServiceRequest :datatype-) "hw4_service_rectangle_area/RectangleAreaServiceRequest")
(setf (get hw4_service_rectangle_area::RectangleAreaServiceRequest :definition-)
      "float32 width
float32 height
---
float32 area
")

(setf (get hw4_service_rectangle_area::RectangleAreaServiceResponse :md5sum-) "92e9c8f940da77dc3e1bc289f7dd146e")
(setf (get hw4_service_rectangle_area::RectangleAreaServiceResponse :datatype-) "hw4_service_rectangle_area/RectangleAreaServiceResponse")
(setf (get hw4_service_rectangle_area::RectangleAreaServiceResponse :definition-)
      "float32 width
float32 height
---
float32 area
")



(provide :hw4_service_rectangle_area/RectangleAreaService "92e9c8f940da77dc3e1bc289f7dd146e")


