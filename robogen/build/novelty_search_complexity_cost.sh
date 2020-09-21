#!/bin/bash
echo "Starting novelty_search complexity cost experiments"
echo "------------------------------------"
echo "finishing experiment set 5"
for x in {6..10}
do
	echo "Running experiment 5:($x/10)."
	./robogen-server 8005 &>/dev/null &
	./robogen-evolver $RANDOM noveltyResults/complexityCost/Experiment5/novelty_output5 ../projectSimulations/novelty_search/evolConf5.txt --save-all --complexity-cost
	echo "Experiment 5:($x/10) finished."
done
echo "Experiment set 5 finished..."
for i in {6..7} 
do
	echo "Running experiment set $i"
	for x in {1..10}
	do
		echo "Running experiment $i:($x/10)."
		./robogen-server 800$i &>/dev/null &
		./robogen-evolver $RANDOM noveltyResults/complexityCost/Experiment$i/novelty_output$i ../projectSimulations/novelty_search/evolConf$i.txt --save-all --complexity-cost
		echo "Experiment $i:($x/10) finished."
	done
	echo "Experiment set $i finished..."
done
echo "Successfully completed all experiments"