echo "Running experiment set 8 baseline"
for x in {3..10}
do
	echo "Running experiment 8:($x/10). b"
	./robogen-server 8008 &>/dev/null &
	./robogen-evolver $RANDOM noveltyResults/baseline/Experiment8/novelty_output8 ../projectSimulations/novelty_search/evolConf8.txt --save-all
	echo "Experiment 8:($x/10) finished. b"
done
echo "Experiment set 9 baseline finished..."
echo "Running experiment set 8 complexityCost"
for x in {1..10}
do
	echo "Running experiment 8:($x/10). cc"
	./robogen-server 8008 &>/dev/null &
	./robogen-evolver $RANDOM noveltyResults/complexityCost/Experiment8/novelty_output8 ../projectSimulations/novelty_search/evolConf8.txt --save-all --complexity-cost
	echo "Experiment 8:($x/10) finished. cc"
done
echo "Experiment set 8 complexityCost finished..."