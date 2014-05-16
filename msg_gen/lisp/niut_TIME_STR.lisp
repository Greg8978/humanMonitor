; Auto-generated. Do not edit!


(cl:in-package humanMonitor-msg)


;//! \htmlinclude niut_TIME_STR.msg.html

(cl:defclass <niut_TIME_STR> (roslisp-msg-protocol:ros-message)
  ((t_sec
    :reader t_sec
    :initarg :t_sec
    :type cl:integer
    :initform 0)
   (t_usec
    :reader t_usec
    :initarg :t_usec
    :type cl:integer
    :initform 0))
)

(cl:defclass niut_TIME_STR (<niut_TIME_STR>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <niut_TIME_STR>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'niut_TIME_STR)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name humanMonitor-msg:<niut_TIME_STR> is deprecated: use humanMonitor-msg:niut_TIME_STR instead.")))

(cl:ensure-generic-function 't_sec-val :lambda-list '(m))
(cl:defmethod t_sec-val ((m <niut_TIME_STR>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader humanMonitor-msg:t_sec-val is deprecated.  Use humanMonitor-msg:t_sec instead.")
  (t_sec m))

(cl:ensure-generic-function 't_usec-val :lambda-list '(m))
(cl:defmethod t_usec-val ((m <niut_TIME_STR>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader humanMonitor-msg:t_usec-val is deprecated.  Use humanMonitor-msg:t_usec instead.")
  (t_usec m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <niut_TIME_STR>) ostream)
  "Serializes a message object of type '<niut_TIME_STR>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 't_sec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 't_sec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 't_sec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 't_sec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 't_usec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 't_usec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 't_usec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 't_usec)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <niut_TIME_STR>) istream)
  "Deserializes a message object of type '<niut_TIME_STR>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 't_sec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 't_sec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 't_sec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 't_sec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 't_usec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 't_usec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 't_usec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 't_usec)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<niut_TIME_STR>)))
  "Returns string type for a message object of type '<niut_TIME_STR>"
  "humanMonitor/niut_TIME_STR")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'niut_TIME_STR)))
  "Returns string type for a message object of type 'niut_TIME_STR"
  "humanMonitor/niut_TIME_STR")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<niut_TIME_STR>)))
  "Returns md5sum for a message object of type '<niut_TIME_STR>"
  "4a84fc51d5840ce74cd63aaf10b060fb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'niut_TIME_STR)))
  "Returns md5sum for a message object of type 'niut_TIME_STR"
  "4a84fc51d5840ce74cd63aaf10b060fb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<niut_TIME_STR>)))
  "Returns full string definition for message of type '<niut_TIME_STR>"
  (cl:format cl:nil "# IDL struct ::niut::TIME_STR~%uint32 t_sec~%uint32 t_usec~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'niut_TIME_STR)))
  "Returns full string definition for message of type 'niut_TIME_STR"
  (cl:format cl:nil "# IDL struct ::niut::TIME_STR~%uint32 t_sec~%uint32 t_usec~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <niut_TIME_STR>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <niut_TIME_STR>))
  "Converts a ROS message object to a list"
  (cl:list 'niut_TIME_STR
    (cl:cons ':t_sec (t_sec msg))
    (cl:cons ':t_usec (t_usec msg))
))
