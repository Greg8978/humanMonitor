; Auto-generated. Do not edit!


(cl:in-package humanMonitor-msg)


;//! \htmlinclude niut_USER_STR.msg.html

(cl:defclass <niut_USER_STR> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type cl:integer
    :initform 0)
   (trackedId
    :reader trackedId
    :initarg :trackedId
    :type cl:integer
    :initform 0)
   (date_discovered
    :reader date_discovered
    :initarg :date_discovered
    :type humanMonitor-msg:niut_TIME_STR
    :initform (cl:make-instance 'humanMonitor-msg:niut_TIME_STR))
   (date
    :reader date
    :initarg :date
    :type humanMonitor-msg:niut_TIME_STR
    :initform (cl:make-instance 'humanMonitor-msg:niut_TIME_STR))
   (state
    :reader state
    :initarg :state
    :type humanMonitor-msg:niut_TRACK_STATE
    :initform (cl:make-instance 'humanMonitor-msg:niut_TRACK_STATE))
   (skeleton
    :reader skeleton
    :initarg :skeleton
    :type humanMonitor-msg:niut_SKELETON_STR
    :initform (cl:make-instance 'humanMonitor-msg:niut_SKELETON_STR)))
)

(cl:defclass niut_USER_STR (<niut_USER_STR>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <niut_USER_STR>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'niut_USER_STR)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name humanMonitor-msg:<niut_USER_STR> is deprecated: use humanMonitor-msg:niut_USER_STR instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <niut_USER_STR>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader humanMonitor-msg:id-val is deprecated.  Use humanMonitor-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'trackedId-val :lambda-list '(m))
(cl:defmethod trackedId-val ((m <niut_USER_STR>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader humanMonitor-msg:trackedId-val is deprecated.  Use humanMonitor-msg:trackedId instead.")
  (trackedId m))

(cl:ensure-generic-function 'date_discovered-val :lambda-list '(m))
(cl:defmethod date_discovered-val ((m <niut_USER_STR>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader humanMonitor-msg:date_discovered-val is deprecated.  Use humanMonitor-msg:date_discovered instead.")
  (date_discovered m))

(cl:ensure-generic-function 'date-val :lambda-list '(m))
(cl:defmethod date-val ((m <niut_USER_STR>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader humanMonitor-msg:date-val is deprecated.  Use humanMonitor-msg:date instead.")
  (date m))

(cl:ensure-generic-function 'state-val :lambda-list '(m))
(cl:defmethod state-val ((m <niut_USER_STR>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader humanMonitor-msg:state-val is deprecated.  Use humanMonitor-msg:state instead.")
  (state m))

(cl:ensure-generic-function 'skeleton-val :lambda-list '(m))
(cl:defmethod skeleton-val ((m <niut_USER_STR>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader humanMonitor-msg:skeleton-val is deprecated.  Use humanMonitor-msg:skeleton instead.")
  (skeleton m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <niut_USER_STR>) ostream)
  "Serializes a message object of type '<niut_USER_STR>"
  (cl:let* ((signed (cl:slot-value msg 'id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'trackedId)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'date_discovered) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'date) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'state) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'skeleton) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <niut_USER_STR>) istream)
  "Deserializes a message object of type '<niut_USER_STR>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'trackedId) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'date_discovered) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'date) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'state) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'skeleton) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<niut_USER_STR>)))
  "Returns string type for a message object of type '<niut_USER_STR>"
  "humanMonitor/niut_USER_STR")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'niut_USER_STR)))
  "Returns string type for a message object of type 'niut_USER_STR"
  "humanMonitor/niut_USER_STR")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<niut_USER_STR>)))
  "Returns md5sum for a message object of type '<niut_USER_STR>"
  "c73ff86e7f31e732cc4478587d7e6354")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'niut_USER_STR)))
  "Returns md5sum for a message object of type 'niut_USER_STR"
  "c73ff86e7f31e732cc4478587d7e6354")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<niut_USER_STR>)))
  "Returns full string definition for message of type '<niut_USER_STR>"
  (cl:format cl:nil "# IDL struct ::niut::USER_STR~%int32 id~%int32 trackedId~%niut_TIME_STR date_discovered~%niut_TIME_STR date~%niut_TRACK_STATE state~%niut_SKELETON_STR skeleton~%~%================================================================================~%MSG: humanMonitor/niut_TIME_STR~%# IDL struct ::niut::TIME_STR~%uint32 t_sec~%uint32 t_usec~%~%================================================================================~%MSG: humanMonitor/niut_TRACK_STATE~%# IDL enum ::niut::TRACK_STATE~%uint32 niut_NO_TRACKING = 0~%uint32 niut_POSE_SEARCH = 1~%uint32 niut_CALIBRATE = 2~%uint32 niut_TRACKING = 3~%~%uint32 value~%~%================================================================================~%MSG: humanMonitor/niut_SKELETON_STR~%# IDL struct ::niut::SKELETON_STR~%niut_JOINT_STR[25] joint~%niut_JOINT unused~%~%================================================================================~%MSG: humanMonitor/niut_JOINT_STR~%# IDL struct ::niut::JOINT_STR~%float64 confidence~%niut_GEN_POINT_3D position~%~%================================================================================~%MSG: humanMonitor/niut_GEN_POINT_3D~%# IDL struct ::niut::GEN_POINT_3D~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: humanMonitor/niut_JOINT~%# IDL enum ::niut::JOINT~%uint32 niut_ZERO = 0~%uint32 niut_HEAD = 1~%uint32 niut_NECK = 2~%uint32 niut_TORSO = 3~%uint32 niut_WAIST = 4~%uint32 niut_LEFT_COLLAR = 5~%uint32 niut_LEFT_SHOULDER = 6~%uint32 niut_LEFT_ELBOW = 7~%uint32 niut_LEFT_WRIST = 8~%uint32 niut_LEFT_HAND = 9~%uint32 niut_LEFT_FINGERTIP = 10~%uint32 niut_RIGHT_COLLAR = 11~%uint32 niut_RIGHT_SHOULDER = 12~%uint32 niut_RIGHT_ELBOW = 13~%uint32 niut_RIGHT_WRIST = 14~%uint32 niut_RIGHT_HAND = 15~%uint32 niut_RIGHT_FINGERTIP = 16~%uint32 niut_LEFT_HIP = 17~%uint32 niut_LEFT_KNEE = 18~%uint32 niut_LEFT_ANKLE = 19~%uint32 niut_LEFT_FOOT = 20~%uint32 niut_RIGHT_HIP = 21~%uint32 niut_RIGHT_KNEE = 22~%uint32 niut_RIGHT_ANKLE = 23~%uint32 niut_RIGHT_FOOT = 24~%~%uint32 value~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'niut_USER_STR)))
  "Returns full string definition for message of type 'niut_USER_STR"
  (cl:format cl:nil "# IDL struct ::niut::USER_STR~%int32 id~%int32 trackedId~%niut_TIME_STR date_discovered~%niut_TIME_STR date~%niut_TRACK_STATE state~%niut_SKELETON_STR skeleton~%~%================================================================================~%MSG: humanMonitor/niut_TIME_STR~%# IDL struct ::niut::TIME_STR~%uint32 t_sec~%uint32 t_usec~%~%================================================================================~%MSG: humanMonitor/niut_TRACK_STATE~%# IDL enum ::niut::TRACK_STATE~%uint32 niut_NO_TRACKING = 0~%uint32 niut_POSE_SEARCH = 1~%uint32 niut_CALIBRATE = 2~%uint32 niut_TRACKING = 3~%~%uint32 value~%~%================================================================================~%MSG: humanMonitor/niut_SKELETON_STR~%# IDL struct ::niut::SKELETON_STR~%niut_JOINT_STR[25] joint~%niut_JOINT unused~%~%================================================================================~%MSG: humanMonitor/niut_JOINT_STR~%# IDL struct ::niut::JOINT_STR~%float64 confidence~%niut_GEN_POINT_3D position~%~%================================================================================~%MSG: humanMonitor/niut_GEN_POINT_3D~%# IDL struct ::niut::GEN_POINT_3D~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: humanMonitor/niut_JOINT~%# IDL enum ::niut::JOINT~%uint32 niut_ZERO = 0~%uint32 niut_HEAD = 1~%uint32 niut_NECK = 2~%uint32 niut_TORSO = 3~%uint32 niut_WAIST = 4~%uint32 niut_LEFT_COLLAR = 5~%uint32 niut_LEFT_SHOULDER = 6~%uint32 niut_LEFT_ELBOW = 7~%uint32 niut_LEFT_WRIST = 8~%uint32 niut_LEFT_HAND = 9~%uint32 niut_LEFT_FINGERTIP = 10~%uint32 niut_RIGHT_COLLAR = 11~%uint32 niut_RIGHT_SHOULDER = 12~%uint32 niut_RIGHT_ELBOW = 13~%uint32 niut_RIGHT_WRIST = 14~%uint32 niut_RIGHT_HAND = 15~%uint32 niut_RIGHT_FINGERTIP = 16~%uint32 niut_LEFT_HIP = 17~%uint32 niut_LEFT_KNEE = 18~%uint32 niut_LEFT_ANKLE = 19~%uint32 niut_LEFT_FOOT = 20~%uint32 niut_RIGHT_HIP = 21~%uint32 niut_RIGHT_KNEE = 22~%uint32 niut_RIGHT_ANKLE = 23~%uint32 niut_RIGHT_FOOT = 24~%~%uint32 value~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <niut_USER_STR>))
  (cl:+ 0
     4
     4
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'date_discovered))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'date))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'state))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'skeleton))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <niut_USER_STR>))
  "Converts a ROS message object to a list"
  (cl:list 'niut_USER_STR
    (cl:cons ':id (id msg))
    (cl:cons ':trackedId (trackedId msg))
    (cl:cons ':date_discovered (date_discovered msg))
    (cl:cons ':date (date msg))
    (cl:cons ':state (state msg))
    (cl:cons ':skeleton (skeleton msg))
))
