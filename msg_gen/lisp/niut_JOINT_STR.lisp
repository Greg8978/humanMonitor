; Auto-generated. Do not edit!


(cl:in-package humanMonitor-msg)


;//! \htmlinclude niut_JOINT_STR.msg.html

(cl:defclass <niut_JOINT_STR> (roslisp-msg-protocol:ros-message)
  ((confidence
    :reader confidence
    :initarg :confidence
    :type cl:float
    :initform 0.0)
   (position
    :reader position
    :initarg :position
    :type humanMonitor-msg:niut_GEN_POINT_3D
    :initform (cl:make-instance 'humanMonitor-msg:niut_GEN_POINT_3D)))
)

(cl:defclass niut_JOINT_STR (<niut_JOINT_STR>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <niut_JOINT_STR>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'niut_JOINT_STR)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name humanMonitor-msg:<niut_JOINT_STR> is deprecated: use humanMonitor-msg:niut_JOINT_STR instead.")))

(cl:ensure-generic-function 'confidence-val :lambda-list '(m))
(cl:defmethod confidence-val ((m <niut_JOINT_STR>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader humanMonitor-msg:confidence-val is deprecated.  Use humanMonitor-msg:confidence instead.")
  (confidence m))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <niut_JOINT_STR>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader humanMonitor-msg:position-val is deprecated.  Use humanMonitor-msg:position instead.")
  (position m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <niut_JOINT_STR>) ostream)
  "Serializes a message object of type '<niut_JOINT_STR>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'confidence))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'position) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <niut_JOINT_STR>) istream)
  "Deserializes a message object of type '<niut_JOINT_STR>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'confidence) (roslisp-utils:decode-double-float-bits bits)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'position) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<niut_JOINT_STR>)))
  "Returns string type for a message object of type '<niut_JOINT_STR>"
  "humanMonitor/niut_JOINT_STR")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'niut_JOINT_STR)))
  "Returns string type for a message object of type 'niut_JOINT_STR"
  "humanMonitor/niut_JOINT_STR")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<niut_JOINT_STR>)))
  "Returns md5sum for a message object of type '<niut_JOINT_STR>"
  "9c2906bba163fd7b5eea616563d91fcd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'niut_JOINT_STR)))
  "Returns md5sum for a message object of type 'niut_JOINT_STR"
  "9c2906bba163fd7b5eea616563d91fcd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<niut_JOINT_STR>)))
  "Returns full string definition for message of type '<niut_JOINT_STR>"
  (cl:format cl:nil "# IDL struct ::niut::JOINT_STR~%float64 confidence~%niut_GEN_POINT_3D position~%~%================================================================================~%MSG: humanMonitor/niut_GEN_POINT_3D~%# IDL struct ::niut::GEN_POINT_3D~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'niut_JOINT_STR)))
  "Returns full string definition for message of type 'niut_JOINT_STR"
  (cl:format cl:nil "# IDL struct ::niut::JOINT_STR~%float64 confidence~%niut_GEN_POINT_3D position~%~%================================================================================~%MSG: humanMonitor/niut_GEN_POINT_3D~%# IDL struct ::niut::GEN_POINT_3D~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <niut_JOINT_STR>))
  (cl:+ 0
     8
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'position))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <niut_JOINT_STR>))
  "Converts a ROS message object to a list"
  (cl:list 'niut_JOINT_STR
    (cl:cons ':confidence (confidence msg))
    (cl:cons ':position (position msg))
))
