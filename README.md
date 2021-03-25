# max-prices-calculation-codeSignal
This program is taking a vector of closing prices of an arbitrary stock.
Also another vector that only contains '0' and '1' which has the same size as the vector before.
'1' means sell and '0' means buy. 
It also takes in an integer k which represents the consecutive number of days that should be 'sell'.
'buy' means the revenue is decreased by the prices of that day.
'sell' means the revenue is increased by the prices of that day.

it will return the max revenue this program can generate.

For example:

k = 4;
algo = < 0, 1, 0, 0, 1, 0, 0>;
prices = <2. 3. 5. 1. 6. 7. 3>;

the return value should be 17.

Without taking into the consideration of k value;

revenue = -2 +3 -5 -1 +6 -7 -3 = -9

With value k of 4,
the most revenue can be generated is 17 because
algo = < 0, 1, 1, 1, 1, 1, 0>;
prices = <2. 3. 5. 1. 6. 7. 3>;

revenue = -2 +3 +5 +1 +6 +7 -3 = 17
