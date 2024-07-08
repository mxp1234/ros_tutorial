;; Auto-generated. Do not edit!


(when (boundp 'plumbing_server_client::addints)
  (if (not (find-package "PLUMBING_SERVER_CLIENT"))
    (make-package "PLUMBING_SERVER_CLIENT"))
  (shadow 'addints (find-package "PLUMBING_SERVER_CLIENT")))
(unless (find-package "PLUMBING_SERVER_CLIENT::ADDINTS")
  (make-package "PLUMBING_SERVER_CLIENT::ADDINTS"))
(unless (find-package "PLUMBING_SERVER_CLIENT::ADDINTSREQUEST")
  (make-package "PLUMBING_SERVER_CLIENT::ADDINTSREQUEST"))
(unless (find-package "PLUMBING_SERVER_CLIENT::ADDINTSRESPONSE")
  (make-package "PLUMBING_SERVER_CLIENT::ADDINTSRESPONSE"))

(in-package "ROS")





(defclass plumbing_server_client::addintsRequest
  :super ros::object
  :slots (_num1 _num2 ))

(defmethod plumbing_server_client::addintsRequest
  (:init
   (&key
    ((:num1 __num1) 0)
    ((:num2 __num2) 0)
    )
   (send-super :init)
   (setq _num1 (round __num1))
   (setq _num2 (round __num2))
   self)
  (:num1
   (&optional __num1)
   (if __num1 (setq _num1 __num1)) _num1)
  (:num2
   (&optional __num2)
   (if __num2 (setq _num2 __num2)) _num2)
  (:serialization-length
   ()
   (+
    ;; int32 _num1
    4
    ;; int32 _num2
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _num1
       (write-long _num1 s)
     ;; int32 _num2
       (write-long _num2 s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _num1
     (setq _num1 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _num2
     (setq _num2 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass plumbing_server_client::addintsResponse
  :super ros::object
  :slots (_sum ))

(defmethod plumbing_server_client::addintsResponse
  (:init
   (&key
    ((:sum __sum) 0)
    )
   (send-super :init)
   (setq _sum (round __sum))
   self)
  (:sum
   (&optional __sum)
   (if __sum (setq _sum __sum)) _sum)
  (:serialization-length
   ()
   (+
    ;; int32 _sum
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _sum
       (write-long _sum s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _sum
     (setq _sum (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass plumbing_server_client::addints
  :super ros::object
  :slots ())

(setf (get plumbing_server_client::addints :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get plumbing_server_client::addints :datatype-) "plumbing_server_client/addints")
(setf (get plumbing_server_client::addints :request) plumbing_server_client::addintsRequest)
(setf (get plumbing_server_client::addints :response) plumbing_server_client::addintsResponse)

(defmethod plumbing_server_client::addintsRequest
  (:response () (instance plumbing_server_client::addintsResponse :init)))

(setf (get plumbing_server_client::addintsRequest :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get plumbing_server_client::addintsRequest :datatype-) "plumbing_server_client/addintsRequest")
(setf (get plumbing_server_client::addintsRequest :definition-)
      "int32 num1
int32 num2
---
int32 sum
")

(setf (get plumbing_server_client::addintsResponse :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get plumbing_server_client::addintsResponse :datatype-) "plumbing_server_client/addintsResponse")
(setf (get plumbing_server_client::addintsResponse :definition-)
      "int32 num1
int32 num2
---
int32 sum
")



(provide :plumbing_server_client/addints "4781436a0c2affec8025955a6041e481")


