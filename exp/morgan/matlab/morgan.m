function [result] = morgan(n,x,y)
    sx = msum(n, x);
    sy = msum(n, y);
    sx2 = msum(n, x .^ 2);
    sy2 = msum(n, y .^ 2);
    sxy = msum(n, x .* y);
    part3 = abs((sy2./n)-(sy./n).^2).^0.5;
    part2 = abs((sx2./n)+(sx./n).^2).^0.5;
    part1 = (sxy./n)-(sx.*sy)./(n.^2);
    result = part1./(part2.*part3);
    % result = ((sxy/n)-(sx.*sy)/(n.^2))./((abs((sx2/n)+(sx/n).^2).^0.5).*(abs((sy2/n)-(sy/n).^2).^0.5));
end
