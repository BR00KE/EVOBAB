#!/bin/bash
echo "Starting novelty_search baseline experiments"
echo "------------------------------------"
do
	echo "Finishing experiment set 5"
	./robogen-server 8005 &>/dev/null &
	./robogen-evolver $RANDOM noveltyResults/baseline/Experiment5/novelty_output5 ../projectSimulations/novelty_search/evolConf5.txt --save-all
	echo "Finished experiment set 5"
done
for i in {6..9} 
do
	echo "Running experiment set $i"
	for x in {1..10}
	do
		echo "Running experiment $i:($x/10)."
		./robogen-server 800$i &>/dev/null &
		./robogen-evolver $RANDOM noveltyResults/baseline/Experiment$i/novelty_output$i ../projectSimulations/novelty_search/evolConf$i.txt --save-all
		echo "Experiment $i:($x/10) finished."
	done
	echo "Experiment set $i finished..."
done
echo "Successfully completed all experiments"
