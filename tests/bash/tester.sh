#!/bin/bash

MYSHELL="$PWD/42sh"
REFER="/bin/tcsh -f"
#REFER="/home/cyrilcolinet/Desktop/42sh"
TRAPSIG=0

CAT=`which cat`
GREP=`which grep`
SED=`which sed`
RM=`which rm`
TR=`which tr`
HEAD=`which head`
TAIL=`which tail`
WC=`which wc`
CHMOD=`which chmod`
EXPR=`which expr`
MKDIR=`which mkdir`
CP=`which cp`

for i in `env | grep BASH_FUNC_ | cut -d= -f1`; do
    f=`echo $i | sed s/BASH_FUNC_//g | sed s/%%//g`
    unset -f $f
done

disp_test()
{
  id=$1
  $CAT tests | $GREP -A1000 "\[$id\]" | $GREP -B1000 "^\[$id-END\]" | $GREP -v "^\[.*\]"
}

run_script()
{
  SC="$1"
  echo -e "$SC" > /tmp/.tmp.$$
  . /tmp/.tmp.$$
  $RM -f /tmp/.tmp.$$
}

prepare_test()
{
  local testfn="/tmp/.tester.$$"
  local runnerfn="/tmp/.runner.$$"
  local refoutfn="/tmp/.refer.$$"
  local shoutfn="/tmp/.shell.$$"

  WRAPPER="$runnerfn"

  echo -e "#!/bin/bash" > $runnerfn
  echo -e "$SETUP" >> $runnerfn
  echo -e "/bin/bash -c '"$testfn" | "$MYSHELL" ; echo Shell exit with code \$?' > "$shoutfn" 2>&1" >> $runnerfn
  echo -e "$CLEAN" >> $runnerfn
  echo -e "$SETUP" >> $runnerfn
  echo -e "$TCSHUPDATE" >> $runnerfn
  echo -e "/bin/bash -c '"$testfn" | "$REFER" ; echo Shell exit with code \$?' > "$refoutfn" 2>&1" >> $runnerfn
  echo -e "$CLEAN" >> $runnerfn

  echo -e "#!/bin/bash" > $testfn
  echo -e "$TESTS" | $TR "²" "\n" >> $testfn

  chmod 755 $testfn
  chmod 755 $runnerfn
}

load_test()
{
  id=$1
  debug=$2
  SETUP=`disp_test "$id" | $GREP "SETUP=" | $SED s/'SETUP='// | $SED s/'"'//g`
  CLEAN=`disp_test "$id" | $GREP "CLEAN=" | $SED s/'CLEAN='// | $SED s/'"'//g`
  NAME=`disp_test "$id" | $GREP "NAME=" | $SED s/'NAME='// | $SED s/'"'//g`
  TCSHUPDATE=`disp_test "$id" | $GREP "TCSHUPDATE=" | $SED s/'TCSHUPDATE='// | $SED s/'"'//g`
  TESTS=`disp_test "$id" | $GREP -v "SETUP=" | $GREP -v "CLEAN=" | $GREP -v "NAME=" | $GREP -v "TCSHUPDATE=" | $GREP -v "TESTS=" | $TR "\n" "²" | $SED s/"²$"//`
  prepare_test
  $WRAPPER
  nb=`$CAT /tmp/.refer.$$ | $GREP -v '^_=' | $GREP -v '^\[1\]' | $WC -l`
  i=1
  ok=1
  while [ $i -le $nb ]
  do
    l=`$CAT /tmp/.refer.$$ | $GREP -v '^_=' | $GREP -v '^\[1\]' | $HEAD -$i | $TAIL -1`
    a=`$CAT /tmp/.shell.$$ | $GREP -v '^_=' | $GREP -v '^\[1\]' | $GREP -- "$l$" | $WC -l`
    if [ $a -eq 0 ]
    then
      ok=0
    fi
    i=`$EXPR $i + 1`
  done

  if [ $ok -eq 1 ]
  then
    if [ $debug -ge 1 ]
    then
      echo -e "Test $id ($NAME) : \033[32m\033[1mOK\033[0m"
      if [ $debug -eq 2 ]
      then
        echo -e "Output $MYSHELL :"
        $CAT -e /tmp/.shell.$$
        echo -e ""
        echo -e "Output $REFER :"
        $CAT -e /tmp/.refer.$$
        echo -e ""
      fi
    else
      echo -e " \033[32m\033[1mOK\033[0m"
    fi
  else
    if [ $debug -ge 1 ]
    then
      echo -e "Test $id ($NAME) : \033[31m\033[1mKO - Check output in /tmp/test.$$/$id/\033[0m"
      $MKDIR -p /tmp/test.$$/$id 2>/dev/null
      $CP /tmp/.shell.$$ /tmp/test.$$/$id/mysh.out
      $CP /tmp/.refer.$$ /tmp/test.$$/$id/tcsh.out
    else
      echo -e "\033[31m\033[1mKO\033[0m"
    fi
  fi
}

if [ $TRAPSIG -eq 1 ]
then
  for sig in `trap -l`
  do
    echo -e "$sig" | grep "^SIG" >/dev/null 2>&1
    if [ $? -eq 0 ]
    then
      trap "echo Received signal $sig !" $sig
    fi
  done
fi

if [ ! -f tests ]
then
  echo -e "No tests file. Please read README.ME" >&2
  exit 1
fi

if [ ! -f $MYSHELL ]
then
  echo -e "$MYSHELL not found" >&2
  exit 1
fi

if [ $# -eq 2 ]
then
  echo -e "Debug mode" >&2
  echo -e "Shell : $MYSHELL" >&2
  echo -e "Reference : $REFER" >&2
  echo -e ""
fi

if [ $# -eq 0 ]
then
  for lst in `cat tests | grep "^\[.*\]$" | grep -vi end | sed s/'\['// | sed s/'\]'//`
  do
    path_backup=$PATH
    load_test $lst 1
    export PATH=$path_backup
  done
else
  if [ $# -eq 1 ]
  then
    load_test $1 0
  else
    if [ "X$1" = "X-d" ]
    then
      load_test $2 2
    else
      load_test $1 2
    fi
  fi
fi
