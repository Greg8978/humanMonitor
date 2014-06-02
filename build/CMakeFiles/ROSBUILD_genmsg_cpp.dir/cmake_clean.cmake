FILE(REMOVE_RECURSE
  "../msg_gen"
  "../msg_gen"
  "../src/humanMonitor/msg"
  "CMakeFiles/ROSBUILD_genmsg_cpp"
  "../msg_gen/cpp/include/humanMonitor/niut_HUMAN_LIST.h"
  "../msg_gen/cpp/include/humanMonitor/niut_TRACK_STATE.h"
  "../msg_gen/cpp/include/humanMonitor/niut_SKELETON_STR.h"
  "../msg_gen/cpp/include/humanMonitor/niut_JOINT_STR.h"
  "../msg_gen/cpp/include/humanMonitor/niut_GEN_POINT_3D.h"
  "../msg_gen/cpp/include/humanMonitor/niut_USER_STR.h"
  "../msg_gen/cpp/include/humanMonitor/niut_TIME_STR.h"
  "../msg_gen/cpp/include/humanMonitor/niut_JOINT.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
