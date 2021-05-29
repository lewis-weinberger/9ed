# Set PLAN9 variable to point to plan9port installation

<$PLAN9/src/mkhdr

DIRS=`ls -1 src/cmd/ | sed -n 's/^/src\/cmd\//p'`

<$PLAN9/src/mkdirs