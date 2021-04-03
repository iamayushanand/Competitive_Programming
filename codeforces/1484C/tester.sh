NONE='\033[00m'
RED='\033[01;31m'
GREEN='\033[04;32m'
YELLOW='\033[01;33m'
PURPLE='\033[01;35m'
CYAN='\033[01;36m'
WHITE='\033[01;37m'
BOLD='\033[1m'
UNDERLINE='\033[4m'

for f in *.in
do
  test_name=${f%.in}
  startTime=`date +%s`
  if ! ./a.out <$test_name.in >$test_name.myout
  then
    echo "$test_name: RE"
  elif diff -bB --strip-trailing-cr $test_name.out $test_name.myout
  then

    endTime=`date +%s`
    if [ "$((endTime-$startTime))" -gt 2000 ]
    then
	    echo "$test_name: ${YELLOW}TLE${NONE}"
    else 
    	    echo -e  "$test_name: ${GREEN}Correct Answer${NONE}"
    	    echo " 	time taken := $((endTime-startTime))ms"
    fi
  else
    echo -e "$test_name: ${RED}Wrong Answer${NONE}"
  fi
done

