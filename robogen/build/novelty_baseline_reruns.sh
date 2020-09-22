echo "rerunning experiment 1."
./robogen-server 8001 &>/dev/null &
./robogen-evolver $RANDOM noveltyResults/baseline/reruns/novelty_output1_2 ../projectSimulations/novelty_search/evolConf1.txt --save-all
./robogen-server 8001 &>/dev/null &
./robogen-evolver $RANDOM noveltyResults/baseline/reruns/novelty_output1_3 ../projectSimulations/novelty_search/evolConf1.txt --save-all
echo "finished reruns for experiment 1"
echo "rerunning experiment 2"
./robogen-server 8002 &>/dev/null &
./robogen-evolver $RANDOM noveltyResults/baseline/reruns/novelty_output2_7 ../projectSimulations/novelty_search/evolConf2.txt --save-all
echo "finished reruns for experiment 2"
echo "rerunning experiment 5"
./robogen-server 8005 &>/dev/null &
./robogen-evolver $RANDOM noveltyResults/baseline/reruns/novelty_output5_1 ../projectSimulations/novelty_search/evolConf5.txt --save-all
echo "finished reruns for experiment 5"
echo "rerunning experiment 7"
./robogen-server 8007 &>/dev/null &
./robogen-evolver $RANDOM noveltyResults/baseline/reruns/novelty_output7_8 ../projectSimulations/novelty_search/evolConf7.txt --save-all
echo "finished reruns for experiment 7"
echo "rerunning experiment 10"
./robogen-server 8010 &>/dev/null &
./robogen-evolver $RANDOM noveltyResults/baseline/reruns/novelty_output10_4 ../projectSimulations/novelty_search/evolConf10.txt --save-all
echo "finished reruns for experiment 10"
echo "rerunning experiment 11"
./robogen-server 8011 &>/dev/null &
./robogen-evolver $RANDOM noveltyResults/baseline/reruns/novelty_output11_7 ../projectSimulations/novelty_search/evolConf11.txt --save-all
echo "finished reruns for experiment 11"