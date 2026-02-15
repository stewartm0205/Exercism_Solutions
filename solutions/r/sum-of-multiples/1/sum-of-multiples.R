sum_of_multiples <- function(factors, limit) {
    mults <- function (x, l) {
        if ( x >= l ) {
            return (c(0))
        }
        seq(x,l-1,x)
    }
    sum(unique(unlist(lapply(factors, mults, l=limit))))
}
