FILE(REMOVE_RECURSE
  "../msg_gen"
  "../msg_gen"
  "../src/humanMonitor/msg"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/humanMonitor/msg/__init__.py"
  "../src/humanMonitor/msg/_niut_HUMAN_LIST.py"
  "../src/humanMonitor/msg/_niut_TRACK_STATE.py"
  "../src/humanMonitor/msg/_niut_SKELETON_STR.py"
  "../src/humanMonitor/msg/_niut_JOINT_STR.py"
  "../src/humanMonitor/msg/_niut_GEN_POINT_3D.py"
  "../src/humanMonitor/msg/_niut_USER_STR.py"
  "../src/humanMonitor/msg/_niut_TIME_STR.py"
  "../src/humanMonitor/msg/_niut_JOINT.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
