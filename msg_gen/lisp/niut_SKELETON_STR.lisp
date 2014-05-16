; Auto-generated. Do not edit!


(cl:in-package humanMonitor-msg)


;//! \htmlinclude niut_SKELETON_STR.msg.html

(cl:defclass <niut_SKELETON_STR> (roslisp-msg-protocol:ros-message)
  ((joint
    :reader joint
    :initarg :joint
    :type (cl:vector humanMonitor-msg:niut_JOINT_STR)
   :initform (cl:make-array 25 :element-type 'humanMonitor-msg:niut_JOINT_STR :initial-element (cl:make-instance 'humanMonitor-msg:niut_JOINT_STR)))
   (unused
    :reader unused
    :initarg :unused
    :type humanMonitor-msg:niut_JOINT
    :initform (cl:make-instance 'humanMonitor-msg:niut_JOINT)))
)

(cl:defclass niut_SKELETON_STR (<niut_SKELETON_STR>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <niut_SKELETON_STR>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'niut_SKELETON_STR)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name humanMonitor-msg:<niut_SKELETON_STR> is deprecated: use humanMonitor-msg:niut_SKELETON_STR instead.")))

(cl:ensure-generic-function 'joint-val :lambda-list '(m))
(cl:defmethod joint-val ((m <niut_SKELETON_STR>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader humanMonitor-msg:joint-val is deprecated.  Use humanMonitor-msg:joint instead.")
  (joint m))

(cl:ensure-generic-function 'unused-val :lambda-list '(m))
(cl:defmethod unused-val ((m <niut_SKELETON_STR>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader humanMonitor-msg:unused-val is deprecated.  Use humanMonitor-msg:unused instead.")
  (unused m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <niut_SKELETON_STR>) ostream)
  "Serializes a message object of type '<niut_SKELETON_STR>"
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'joint))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'unused) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <niut_SKELETON_STR>) istream)
  "Deserializes a message object of type '<niut_SKELETON_STR>"
  (cl:setf (cl:slot-value msg 'joint) (cl:make-array 25))
  (cl:let ((vals (cl:slot-value msg 'joint)))
    (cl:dotimes (i 25)
    (cl:setf (cl:aref vals i) (cl:make-instance 'humanMonitor-msg:niut_JOINT_STR))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'unused) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<niut_SKELETON_STR>)))
  "Returns string type for a message object of type '<niut_SKELETON_STR>"
  "humanMonitor/niut_SKELETON_STR")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'niut_SKELETON_STR)))
  "Returns string type for a message object of type 'niut_SKELETON_STR"
  "humanMonitor/niut_SKELETON_STR")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<niut_SKELETON_STR>)))
  "Returns md5sum for a message object of type '<niut_SKELETON_STR>"
  "d429f56f311dd3d55d503fb55fdca0ed")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'niut_SKELETON_STR)))
  "Returns md5sum for a message object of type 'niut_SKELETON_STR"
  "d429f56f311dd3d55d503fb55fdca0ed")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<niut_SKELETON_STR>)))
  "Returns full string definition for message of type '<niut_SKELETON_STR>"
  (cl:format cl:nil "# IDL struct ::niut::SKELETON_STR~%niut_JOINT_STR[25] joint~%niut_JOINT unused~%~%================================================================================~%MSG: humanMonitor/niut_JOINT_STR~%# IDL struct ::niut::JOINT_STR~%float64 confidence~%niut_GEN_POINT_3D position~%~%================================================================================~%MSG: humanMonitor/niut_GEN_POINT_3D~%# IDL struct ::niut::GEN_POINT_3D~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: humanMonitor/niut_JOINT~%# IDL enum ::niut::JOINT~%uint32 niut_ZERO = 0~%uint32 niut_HEAD = 1~%uint32 niut_NECK = 2~%uint32 niut_TORSO = 3~%uint32 niut_WAIST = 4~%uint32 niut_LEFT_COLLAR = 5~%uint32 niut_LEFT_SHOULDER = 6~%uint32 niut_LEFT_ELBOW = 7~%uint32 niut_LEFT_WRIST = 8~%uint32 niut_LEFT_HAND = 9~%uint32 niut_LEFT_FINGERTIP = 10~%uint32 niut_RIGHT_COLLAR = 11~%uint32 niut_RIGHT_SHOULDER = 12~%uint32 niut_RIGHT_ELBOW = 13~%uint32 niut_RIGHT_WRIST = 14~%uint32 niut_RIGHT_HAND = 15~%uint32 niut_RIGHT_FINGERTIP = 16~%uint32 niut_LEFT_HIP = 17~%uint32 niut_LEFT_KNEE = 18~%uint32 niut_LEFT_ANKLE = 19~%uint32 niut_LEFT_FOOT = 20~%uint32 niut_RIGHT_HIP = 21~%uint32 niut_RIGHT_KNEE = 22~%uint32 niut_RIGHT_ANKLE = 23~%uint32 niut_RIGHT_FOOT = 24~%~%uint32 value~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'niut_SKELETON_STR)))
  "Returns full string definition for message of type 'niut_SKELETON_STR"
  (cl:format cl:nil "# IDL struct ::niut::SKELETON_STR~%niut_JOINT_STR[25] joint~%niut_JOINT unused~%~%================================================================================~%MSG: humanMonitor/niut_JOINT_STR~%# IDL struct ::niut::JOINT_STR~%float64 confidence~%niut_GEN_POINT_3D position~%~%================================================================================~%MSG: humanMonitor/niut_GEN_POINT_3D~%# IDL struct ::niut::GEN_POINT_3D~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: humanMonitor/niut_JOINT~%# IDL enum ::niut::JOINT~%uint32 niut_ZERO = 0~%uint32 niut_HEAD = 1~%uint32 niut_NECK = 2~%uint32 niut_TORSO = 3~%uint32 niut_WAIST = 4~%uint32 niut_LEFT_COLLAR = 5~%uint32 niut_LEFT_SHOULDER = 6~%uint32 niut_LEFT_ELBOW = 7~%uint32 niut_LEFT_WRIST = 8~%uint32 niut_LEFT_HAND = 9~%uint32 niut_LEFT_FINGERTIP = 10~%uint32 niut_RIGHT_COLLAR = 11~%uint32 niut_RIGHT_SHOULDER = 12~%uint32 niut_RIGHT_ELBOW = 13~%uint32 niut_RIGHT_WRIST = 14~%uint32 niut_RIGHT_HAND = 15~%uint32 niut_RIGHT_FINGERTIP = 16~%uint32 niut_LEFT_HIP = 17~%uint32 niut_LEFT_KNEE = 18~%uint32 niut_LEFT_ANKLE = 19~%uint32 niut_LEFT_FOOT = 20~%uint32 niut_RIGHT_HIP = 21~%uint32 niut_RIGHT_KNEE = 22~%uint32 niut_RIGHT_ANKLE = 23~%uint32 niut_RIGHT_FOOT = 24~%~%uint32 value~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <niut_SKELETON_STR>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'joint) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'unused))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <niut_SKELETON_STR>))
  "Converts a ROS message object to a list"
  (cl:list 'niut_SKELETON_STR
    (cl:cons ':joint (joint msg))
    (cl:cons ':unused (unused msg))
))
