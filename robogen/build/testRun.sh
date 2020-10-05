echo "Testing all experiments"
echo "Population size:10, number of generations:5"
echo "---------------------------------------------"
echo "Objective-based search"

./robogen-server 8000 &>/dev/null &
./robogen-evolver $RANDOM testRunResults/objective_based/ ../projectSimulations/dummy_confs/evolConf0.txt --save-all	

echo "Objective-based search finished..."

echo "Objective-based search with complexity cost"

./robogen-server 8000 &>/dev/null &
./robogen-evolver $RANDOM testRunResults/objective_based_complexity_cost/ ../projectSimulations/dummy_confs/evolConf0.txt --save-all	

echo "Objective-based search with complexity cost finished..."

echo "Novelty-based search"

./robogen-server 8001 &>/dev/null &
./robogen-evolver $RANDOM testRunResults/novelty/ ../projectSimulations/dummy_confs/evolConf1.txt --save-all	

echo "Novelty search finished..."

echo "Novelty search with complexity cost"

./robogen-server 8001 &>/dev/null &
./robogen-evolver $RANDOM testRunResults/novelty_complexity_cost/ ../projectSimulations/dummy_confs/evolConf1.txt --save-all	

echo "Novelty search with complexity cost finished..."