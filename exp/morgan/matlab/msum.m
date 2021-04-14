function [result] = msum(n,a)
    t = cumsum(a);
    len = length(a);
    result = t((n+1):len) - t(1:(len-n));
end
