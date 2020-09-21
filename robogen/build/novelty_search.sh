#!/bin/bash
echo "Starting novelty_search baseline experiments"
echo "------------------------------------"

echo "Finishing experiment set 6"
./robogen-server 8006 &>/dev/null &
./robogen-evolver $RANDOM noveltyResults/baseline/Experiment6/novelty_output6 ../projectSimulations/novelty_search/evolConf6.txt --save-all
echo "Finished experiment set 6"

for i in {7..8} 
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
