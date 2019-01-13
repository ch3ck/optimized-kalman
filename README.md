# optmized-kalman
Optmized kalman filters

## Description
Optimized 2D kalman filter 


## Build
```
λ git clone git@github.com:Ch3ck/optmized-kalman.git
λ cd optimized-kalman
λ make && ./kalman
```


## Benchmark Results

### Before
```
number of iterations: 10000 
duration milliseconds initialize beliefs 44.313
duration milliseconds sense 56.789
duration milliseconds blur 131.913
duration milliseconds normalize 52.679
duration milliseconds move 44.001
```

### After
```
number of iterations: 10000 
duration milliseconds initialize beliefs 12.879
duration milliseconds sense 13.082
duration milliseconds blur 55.614
duration milliseconds normalize 12.03
duration milliseconds move 15.498
```

## Contributing
If you encounter a bug problems, I'll like to hear about it. Also, pull requests are welcomed

## Author
- Ping me on Twitter [@nyah_check](https://twitter.com/nyah_check)
