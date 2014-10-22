while (T > T_min) {
    dE = J(y[i + 1]) - J(y[i]);
    if (dE >= 0) y[i + 1] = y[i];
    else {
        if (exp(dE / T) > random(0, 1)) {
            y[i + 1] = y[i];
        }
        T *= r;
        i ++;
    }
}
