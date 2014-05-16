; Auto-generated. Do not edit!


(cl:in-package humanMonitor-msg)


;//! \htmlinclude niut_HUMAN_LIST.msg.html

(cl:defclass <niut_HUMAN_LIST> (roslisp-msg-protocol:ros-message)
  ((watch_dog
    :reader watch_dog
    :initarg :watch_dog
    :type cl:integer
    :initform 0)
   (num
    :reader num
    :initarg :num
    :type cl:integer
    :initform 0)
   (users
    :reader users
    :initarg :users
    :type (cl:vector humanMonitor-msg:niut_USER_STR)
   :initform (cl:make-array 16 :element-type 'humanMonitor-msg:niut_USER_STR :initial-element (cl:make-instance 'humanMonitor-msg:niut_USER_STR)))
   (filtered_users
    :reader filtered_users
    :initarg :filtered_users
    :type (cl:vector humanMonitor-msg:niut_USER_STR)
   :initform (cl:make-array 16 :element-type 'humanMonitor-msg:niut_USER_STR :initial-element (cl:make-instance 'humanMonitor-msg:niut_USER_STR))))
)

(cl:defclass niut_HUMAN_LIST (<niut_HUMAN_LIST>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <niut_HUMAN_LIST>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'niut_HUMAN_LIST)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name humanMonitor-msg:<niut_HUMAN_LIST> is deprecated: use humanMonitor-msg:niut_HUMAN_LIST instead.")))

(cl:ensure-generic-function 'watch_dog-val :lambda-list '(m))
(cl:defmethod watch_dog-val ((m <niut_HUMAN_LIST>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader humanMonitor-msg:watch_dog-val is deprecated.  Use humanMonitor-msg:watch_dog instead.")
  (watch_dog m))

(cl:ensure-generic-function 'num-val :lambda-list '(m))
(cl:defmethod num-val ((m <niut_HUMAN_LIST>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader humanMonitor-msg:num-val is deprecated.  Use humanMonitor-msg:num instead.")
  (num m))

(cl:ensure-generic-function 'users-val :lambda-list '(m))
(cl:defmethod users-val ((m <niut_HUMAN_LIST>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader humanMonitor-msg:users-val is deprecated.  Use humanMonitor-msg:users instead.")
  (users m))

(cl:ensure-generic-function 'filtered_users-val :lambda-list '(m))
(cl:defmethod filtered_users-val ((m <niut_HUMAN_LIST>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader humanMonitor-msg:filtered_users-val is deprecated.  Use humanMonitor-msg:filtered_users instead.")
  (filtered_users m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <niut_HUMAN_LIST>) ostream)
  "Serializes a message object of type '<niut_HUMAN_LIST>"
  (cl:let* ((signed (cl:slot-value msg 'watch_dog)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'num)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'users))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'filtered_users))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <niut_HUMAN_LIST>) istream)
  "Deserializes a message object of type '<niut_HUMAN_LIST>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'watch_dog) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'num) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (cl:setf (cl:slot-value msg 'users) (cl:make-array 16))
  (cl:let ((vals (cl:slot-value msg 'users)))
    (cl:dotimes (i 16)
    (cl:setf (cl:aref vals i) (cl:make-instance 'humanMonitor-msg:niut_USER_STR))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (cl:setf (cl:slot-value msg 'filtered_users) (cl:make-array 16))
  (cl:let ((vals (cl:slot-value msg 'filtered_users)))
    (cl:dotimes (i 16)
    (cl:setf (cl:aref vals i) (cl:make-instance 'humanMonitor-msg:niut_USER_STR))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<niut_HUMAN_LIST>)))
  "Returns string type for a message object of type '<niut_HUMAN_LIST>"
  "humanMonitor/niut_HUMAN_LIST")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'niut_HUMAN_LIST)))
  "Returns string type for a message object of type 'niut_HUMAN_LIST"
  "humanMonitor/niut_HUMAN_LIST")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<niut_HUMAN_LIST>)))
  "Returns md5sum for a message object of type '<niut_HUMAN_LIST>"
  "9442f7b60b19634aa64749beaf671cc9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'niut_HUMAN_LIST)))
  "Returns md5sum for a message object of type 'niut_HUMAN_LIST"
  "9442f7b60b19634aa64749beaf671cc9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<niut_HUMAN_LIST>)))
  "Returns full string definition for message of type '<niut_HUMAN_LIST>"
  (cl:format cl:nil "# IDL struct ::niut::HUMAN_LIST~%int32 watch_dog~%int32 num~%niut_USER_STR[16] users~%niut_USER_STR[16] filtered_users~%~%================================================================================~%MSG: humanMonitor/niut_USER_STR~%# IDL struct ::niut::USER_STR~%int32 id~%int32 trackedId~%niut_TIME_STR date_discovered~%niut_TIME_STR date~%niut_TRACK_STATE state~%niut_SKELETON_STR skeleton~%~%================================================================================~%MSG: humanMonitor/niut_TIME_STR~%# IDL struct ::niut::TIME_STR~%uint32 t_sec~%uint32 t_usec~%~%================================================================================~%MSG: humanMonitor/niut_TRACK_STATE~%# IDL enum ::niut::TRACK_STATE~%uint32 niut_NO_TRACKING = 0~%uint32 niut_POSE_SEARCH = 1~%uint32 niut_CALIBRATE = 2~%uint32 niut_TRACKING = 3~%~%uint32 value~%~%================================================================================~%MSG: humanMonitor/niut_SKELETON_STR~%# IDL struct ::niut::SKELETON_STR~%niut_JOINT_STR[25] joint~%niut_JOINT unused~%~%================================================================================~%MSG: humanMonitor/niut_JOINT_STR~%# IDL struct ::niut::JOINT_STR~%float64 confidence~%niut_GEN_POINT_3D position~%~%================================================================================~%MSG: humanMonitor/niut_GEN_POINT_3D~%# IDL struct ::niut::GEN_POINT_3D~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: humanMonitor/niut_JOINT~%# IDL enum ::niut::JOINT~%uint32 niut_ZERO = 0~%uint32 niut_HEAD = 1~%uint32 niut_NECK = 2~%uint32 niut_TORSO = 3~%uint32 niut_WAIST = 4~%uint32 niut_LEFT_COLLAR = 5~%uint32 niut_LEFT_SHOULDER = 6~%uint32 niut_LEFT_ELBOW = 7~%uint32 niut_LEFT_WRIST = 8~%uint32 niut_LEFT_HAND = 9~%uint32 niut_LEFT_FINGERTIP = 10~%uint32 niut_RIGHT_COLLAR = 11~%uint32 niut_RIGHT_SHOULDER = 12~%uint32 niut_RIGHT_ELBOW = 13~%uint32 niut_RIGHT_WRIST = 14~%uint32 niut_RIGHT_HAND = 15~%uint32 niut_RIGHT_FINGERTIP = 16~%uint32 niut_LEFT_HIP = 17~%uint32 niut_LEFT_KNEE = 18~%uint32 niut_LEFT_ANKLE = 19~%uint32 niut_LEFT_FOOT = 20~%uint32 niut_RIGHT_HIP = 21~%uint32 niut_RIGHT_KNEE = 22~%uint32 niut_RIGHT_ANKLE = 23~%uint32 niut_RIGHT_FOOT = 24~%~%uint32 value~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'niut_HUMAN_LIST)))
  "Returns full string definition for message of type 'niut_HUMAN_LIST"
  (cl:format cl:nil "# IDL struct ::niut::HUMAN_LIST~%int32 watch_dog~%int32 num~%niut_USER_STR[16] users~%niut_USER_STR[16] filtered_users~%~%================================================================================~%MSG: humanMonitor/niut_USER_STR~%# IDL struct ::niut::USER_STR~%int32 id~%int32 trackedId~%niut_TIME_STR date_discovered~%niut_TIME_STR date~%niut_TRACK_STATE state~%niut_SKELETON_STR skeleton~%~%================================================================================~%MSG: humanMonitor/niut_TIME_STR~%# IDL struct ::niut::TIME_STR~%uint32 t_sec~%uint32 t_usec~%~%================================================================================~%MSG: humanMonitor/niut_TRACK_STATE~%# IDL enum ::niut::TRACK_STATE~%uint32 niut_NO_TRACKING = 0~%uint32 niut_POSE_SEARCH = 1~%uint32 niut_CALIBRATE = 2~%uint32 niut_TRACKING = 3~%~%uint32 value~%~%================================================================================~%MSG: humanMonitor/niut_SKELETON_STR~%# IDL struct ::niut::SKELETON_STR~%niut_JOINT_STR[25] joint~%niut_JOINT unused~%~%================================================================================~%MSG: humanMonitor/niut_JOINT_STR~%# IDL struct ::niut::JOINT_STR~%float64 confidence~%niut_GEN_POINT_3D position~%~%================================================================================~%MSG: humanMonitor/niut_GEN_POINT_3D~%# IDL struct ::niut::GEN_POINT_3D~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: humanMonitor/niut_JOINT~%# IDL enum ::niut::JOINT~%uint32 niut_ZERO = 0~%uint32 niut_HEAD = 1~%uint32 niut_NECK = 2~%uint32 niut_TORSO = 3~%uint32 niut_WAIST = 4~%uint32 niut_LEFT_COLLAR = 5~%uint32 niut_LEFT_SHOULDER = 6~%uint32 niut_LEFT_ELBOW = 7~%uint32 niut_LEFT_WRIST = 8~%uint32 niut_LEFT_HAND = 9~%uint32 niut_LEFT_FINGERTIP = 10~%uint32 niut_RIGHT_COLLAR = 11~%uint32 niut_RIGHT_SHOULDER = 12~%uint32 niut_RIGHT_ELBOW = 13~%uint32 niut_RIGHT_WRIST = 14~%uint32 niut_RIGHT_HAND = 15~%uint32 niut_RIGHT_FINGERTIP = 16~%uint32 niut_LEFT_HIP = 17~%uint32 niut_LEFT_KNEE = 18~%uint32 niut_LEFT_ANKLE = 19~%uint32 niut_LEFT_FOOT = 20~%uint32 niut_RIGHT_HIP = 21~%uint32 niut_RIGHT_KNEE = 22~%uint32 niut_RIGHT_ANKLE = 23~%uint32 niut_RIGHT_FOOT = 24~%~%uint32 value~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <niut_HUMAN_LIST>))
  (cl:+ 0
     4
     4
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'users) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'filtered_users) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <niut_HUMAN_LIST>))
  "Converts a ROS message object to a list"
  (cl:list 'niut_HUMAN_LIST
    (cl:cons ':watch_dog (watch_dog msg))
    (cl:cons ':num (num msg))
    (cl:cons ':users (users msg))
    (cl:cons ':filtered_users (filtered_users msg))
))
