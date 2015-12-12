echo 'gcc gauss - profile disable'
time ./gauss_gcc_disable_profile.exe
echo '~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~'

echo 'gcc gauss - profile enable'
time ./gauss_gcc_enable_profile.exe
gprof ./gauss_gcc_enable_profile.exe > gcc_profile_data.txt 
echo '~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~'

echo 'icc gauss - profile disable'
time ./gauss_icc_disable_profile.exe
echo '~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~'

echo 'icc gauss - profile enable'
time ./gauss_icc_enable_profile.exe
gprof ./gauss_gcc_enable_profile.exe > icc_profile_data.txt 
echo '~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~'
