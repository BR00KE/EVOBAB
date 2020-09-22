echo "reRunning experiment 3"
./robogen-server 8003 &>/dev/null &
./robogen-evolver $RANDOM noveltyResults/complexityCost/reruns/novelty_output3_8 ../projectSimulations/novelty_search/evolConf3.txt --save-all --complexity-cost
echo "Experiment 3 rerun finished."
echo "reRunning experiment 6"
./robogen-server 8006 &>/dev/null &
./robogen-evolver $RANDOM noveltyResults/complexityCost/reruns/novelty_output6_8 ../projectSimulations/novelty_search/evolConf6.txt --save-all --complexity-cost
echo "Experiment 6 rerun finished."
echo "reRunning experiment 2"
./robogen-server 8002 &>/dev/null &
./robogen-evolver $RANDOM noveltyResults/complexityCost/reruns/novelty_output2_4 ../projectSimulations/novelty_search/evolConf2.txt --save-all --complexity-cost
echo "Experiment 2 rerun finished."
echo "reRunning experiment 1"
./robogen-server 8001 &>/dev/null &
./robogen-evolver $RANDOM noveltyResults/complexityCost/reruns/novelty_output1_9 ../projectSimulations/novelty_search/evolConf1.txt --save-all --complexity-cost
echo "Experiment 1 rerun finished."
echo "reRunning experiment 9"
./robogen-server 8009 &>/dev/null &
./robogen-evolver $RANDOM noveltyResults/complexityCost/reruns/novelty_output9_5 ../projectSimulations/novelty_search/evolConf9.txt --save-all --complexity-cost
echo "Experiment 9 rerun finished."