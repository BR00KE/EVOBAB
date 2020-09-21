echo "Finishing experiment 10 for objective search with complexity cost"

echo "Running experiment set 7"
for x in {1..10}
do
	num=$((7 + 12))
	echo "Running experiment 7:($x/10)."
	./robogen-server 80$num &>/dev/null &
	./robogen-evolver $RANDOM objectiveResults/complexityCost/Experiment7/objective_output7 ../projectSimulations/objective_based_cost/evolConf7.txt --save-all --complexity-cost
	echo "Experiment 7:($x/10) finished."
done
echo "Experiment set 7 finished..."