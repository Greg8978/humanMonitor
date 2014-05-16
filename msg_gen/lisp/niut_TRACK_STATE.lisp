; Auto-generated. Do not edit!


(cl:in-package humanMonitor-msg)


;//! \htmlinclude niut_TRACK_STATE.msg.html

(cl:defclass <niut_TRACK_STATE> (roslisp-msg-protocol:ros-message)
  ((value
    :reader value
    :initarg :value
    :type cl:integer
    :initform 0))
)

(cl:defclass niut_TRACK_STATE (<niut_TRACK_STATE>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <niut_TRACK_STATE>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'niut_TRACK_STATE)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name humanMonitor-msg:<niut_TRACK_STATE> is deprecated: use humanMonitor-msg:niut_TRACK_STATE instead.")))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <niut_TRACK_STATE>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader humanMonitor-msg:value-val is deprecated.  Use humanMonitor-msg:value instead.")
  (value m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<niut_TRACK_STATE>)))
    "Constants for message type '<niut_TRACK_STATE>"
  '((:NIUT_NO_TRACKING . 0)
    (:NIUT_POSE_SEARCH . 1)
    (:NIUT_CALIBRATE . 2)
    (:NIUT_TRACKING . 3))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'niut_TRACK_STATE)))
    "Constants for message type 'niut_TRACK_STATE"
  '((:NIUT_NO_TRACKING . 0)
    (:NIUT_POSE_SEARCH . 1)
    (:NIUT_CALIBRATE . 2)
    (:NIUT_TRACKING . 3))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <niut_TRACK_STATE>) ostream)
  "Serializes a message object of type '<niut_TRACK_STATE>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'value)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'value)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'value)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'value)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <niut_TRACK_STATE>) istream)
  "Deserializes a message object of type '<niut_TRACK_STATE>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'value)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'value)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'value)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'value)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<niut_TRACK_STATE>)))
  "Returns string type for a message object of type '<niut_TRACK_STATE>"
  "humanMonitor/niut_TRACK_STATE")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'niut_TRACK_STATE)))
  "Returns string type for a message object of type 'niut_TRACK_STATE"
  "humanMonitor/niut_TRACK_STATE")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<niut_TRACK_STATE>)))
  "Returns md5sum for a message object of type '<niut_TRACK_STATE>"
  "2f590b5cd751e2c0d69fe35f4a3b66d8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'niut_TRACK_STATE)))
  "Returns md5sum for a message object of type 'niut_TRACK_STATE"
  "2f590b5cd751e2c0d69fe35f4a3b66d8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<niut_TRACK_STATE>)))
  "Returns full string definition for message of type '<niut_TRACK_STATE>"
  (cl:format cl:nil "# IDL enum ::niut::TRACK_STATE~%uint32 niut_NO_TRACKING = 0~%uint32 niut_POSE_SEARCH = 1~%uint32 niut_CALIBRATE = 2~%uint32 niut_TRACKING = 3~%~%uint32 value~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'niut_TRACK_STATE)))
  "Returns full string definition for message of type 'niut_TRACK_STATE"
  (cl:format cl:nil "# IDL enum ::niut::TRACK_STATE~%uint32 niut_NO_TRACKING = 0~%uint32 niut_POSE_SEARCH = 1~%uint32 niut_CALIBRATE = 2~%uint32 niut_TRACKING = 3~%~%uint32 value~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <niut_TRACK_STATE>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <niut_TRACK_STATE>))
  "Converts a ROS message object to a list"
  (cl:list 'niut_TRACK_STATE
    (cl:cons ':value (value msg))
))
