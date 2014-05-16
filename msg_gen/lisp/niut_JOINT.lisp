; Auto-generated. Do not edit!


(cl:in-package humanMonitor-msg)


;//! \htmlinclude niut_JOINT.msg.html

(cl:defclass <niut_JOINT> (roslisp-msg-protocol:ros-message)
  ((value
    :reader value
    :initarg :value
    :type cl:integer
    :initform 0))
)

(cl:defclass niut_JOINT (<niut_JOINT>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <niut_JOINT>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'niut_JOINT)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name humanMonitor-msg:<niut_JOINT> is deprecated: use humanMonitor-msg:niut_JOINT instead.")))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <niut_JOINT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader humanMonitor-msg:value-val is deprecated.  Use humanMonitor-msg:value instead.")
  (value m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<niut_JOINT>)))
    "Constants for message type '<niut_JOINT>"
  '((:NIUT_ZERO . 0)
    (:NIUT_HEAD . 1)
    (:NIUT_NECK . 2)
    (:NIUT_TORSO . 3)
    (:NIUT_WAIST . 4)
    (:NIUT_LEFT_COLLAR . 5)
    (:NIUT_LEFT_SHOULDER . 6)
    (:NIUT_LEFT_ELBOW . 7)
    (:NIUT_LEFT_WRIST . 8)
    (:NIUT_LEFT_HAND . 9)
    (:NIUT_LEFT_FINGERTIP . 10)
    (:NIUT_RIGHT_COLLAR . 11)
    (:NIUT_RIGHT_SHOULDER . 12)
    (:NIUT_RIGHT_ELBOW . 13)
    (:NIUT_RIGHT_WRIST . 14)
    (:NIUT_RIGHT_HAND . 15)
    (:NIUT_RIGHT_FINGERTIP . 16)
    (:NIUT_LEFT_HIP . 17)
    (:NIUT_LEFT_KNEE . 18)
    (:NIUT_LEFT_ANKLE . 19)
    (:NIUT_LEFT_FOOT . 20)
    (:NIUT_RIGHT_HIP . 21)
    (:NIUT_RIGHT_KNEE . 22)
    (:NIUT_RIGHT_ANKLE . 23)
    (:NIUT_RIGHT_FOOT . 24))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'niut_JOINT)))
    "Constants for message type 'niut_JOINT"
  '((:NIUT_ZERO . 0)
    (:NIUT_HEAD . 1)
    (:NIUT_NECK . 2)
    (:NIUT_TORSO . 3)
    (:NIUT_WAIST . 4)
    (:NIUT_LEFT_COLLAR . 5)
    (:NIUT_LEFT_SHOULDER . 6)
    (:NIUT_LEFT_ELBOW . 7)
    (:NIUT_LEFT_WRIST . 8)
    (:NIUT_LEFT_HAND . 9)
    (:NIUT_LEFT_FINGERTIP . 10)
    (:NIUT_RIGHT_COLLAR . 11)
    (:NIUT_RIGHT_SHOULDER . 12)
    (:NIUT_RIGHT_ELBOW . 13)
    (:NIUT_RIGHT_WRIST . 14)
    (:NIUT_RIGHT_HAND . 15)
    (:NIUT_RIGHT_FINGERTIP . 16)
    (:NIUT_LEFT_HIP . 17)
    (:NIUT_LEFT_KNEE . 18)
    (:NIUT_LEFT_ANKLE . 19)
    (:NIUT_LEFT_FOOT . 20)
    (:NIUT_RIGHT_HIP . 21)
    (:NIUT_RIGHT_KNEE . 22)
    (:NIUT_RIGHT_ANKLE . 23)
    (:NIUT_RIGHT_FOOT . 24))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <niut_JOINT>) ostream)
  "Serializes a message object of type '<niut_JOINT>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'value)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'value)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'value)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'value)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <niut_JOINT>) istream)
  "Deserializes a message object of type '<niut_JOINT>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'value)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'value)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'value)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'value)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<niut_JOINT>)))
  "Returns string type for a message object of type '<niut_JOINT>"
  "humanMonitor/niut_JOINT")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'niut_JOINT)))
  "Returns string type for a message object of type 'niut_JOINT"
  "humanMonitor/niut_JOINT")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<niut_JOINT>)))
  "Returns md5sum for a message object of type '<niut_JOINT>"
  "0e470f210f9f1090b60cbbd9da53831f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'niut_JOINT)))
  "Returns md5sum for a message object of type 'niut_JOINT"
  "0e470f210f9f1090b60cbbd9da53831f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<niut_JOINT>)))
  "Returns full string definition for message of type '<niut_JOINT>"
  (cl:format cl:nil "# IDL enum ::niut::JOINT~%uint32 niut_ZERO = 0~%uint32 niut_HEAD = 1~%uint32 niut_NECK = 2~%uint32 niut_TORSO = 3~%uint32 niut_WAIST = 4~%uint32 niut_LEFT_COLLAR = 5~%uint32 niut_LEFT_SHOULDER = 6~%uint32 niut_LEFT_ELBOW = 7~%uint32 niut_LEFT_WRIST = 8~%uint32 niut_LEFT_HAND = 9~%uint32 niut_LEFT_FINGERTIP = 10~%uint32 niut_RIGHT_COLLAR = 11~%uint32 niut_RIGHT_SHOULDER = 12~%uint32 niut_RIGHT_ELBOW = 13~%uint32 niut_RIGHT_WRIST = 14~%uint32 niut_RIGHT_HAND = 15~%uint32 niut_RIGHT_FINGERTIP = 16~%uint32 niut_LEFT_HIP = 17~%uint32 niut_LEFT_KNEE = 18~%uint32 niut_LEFT_ANKLE = 19~%uint32 niut_LEFT_FOOT = 20~%uint32 niut_RIGHT_HIP = 21~%uint32 niut_RIGHT_KNEE = 22~%uint32 niut_RIGHT_ANKLE = 23~%uint32 niut_RIGHT_FOOT = 24~%~%uint32 value~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'niut_JOINT)))
  "Returns full string definition for message of type 'niut_JOINT"
  (cl:format cl:nil "# IDL enum ::niut::JOINT~%uint32 niut_ZERO = 0~%uint32 niut_HEAD = 1~%uint32 niut_NECK = 2~%uint32 niut_TORSO = 3~%uint32 niut_WAIST = 4~%uint32 niut_LEFT_COLLAR = 5~%uint32 niut_LEFT_SHOULDER = 6~%uint32 niut_LEFT_ELBOW = 7~%uint32 niut_LEFT_WRIST = 8~%uint32 niut_LEFT_HAND = 9~%uint32 niut_LEFT_FINGERTIP = 10~%uint32 niut_RIGHT_COLLAR = 11~%uint32 niut_RIGHT_SHOULDER = 12~%uint32 niut_RIGHT_ELBOW = 13~%uint32 niut_RIGHT_WRIST = 14~%uint32 niut_RIGHT_HAND = 15~%uint32 niut_RIGHT_FINGERTIP = 16~%uint32 niut_LEFT_HIP = 17~%uint32 niut_LEFT_KNEE = 18~%uint32 niut_LEFT_ANKLE = 19~%uint32 niut_LEFT_FOOT = 20~%uint32 niut_RIGHT_HIP = 21~%uint32 niut_RIGHT_KNEE = 22~%uint32 niut_RIGHT_ANKLE = 23~%uint32 niut_RIGHT_FOOT = 24~%~%uint32 value~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <niut_JOINT>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <niut_JOINT>))
  "Converts a ROS message object to a list"
  (cl:list 'niut_JOINT
    (cl:cons ':value (value msg))
))
