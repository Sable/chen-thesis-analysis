function run(input_file, runs)
    fprintf('[%s] Loading ...\n', input_file);
    tic;
    n = 1000;
    data = readtable(input_file, 'Delimiter', ' ', 'ReadVariableNames', false);
    x = table2array(data(:,1));
    y = table2array(data(:,2));
    % disp(x(1:10));
    % disp(y(1:10));
    load_time = toc;
    fprintf('[%s] Loaded in %.2f s\n', input_file, load_time);
    for id = 1:5
        result = morgan(n,x,y);
    end
    elapsed = zeros(1, runs);
    for k = 1:runs
        tic;
        result = morgan(n,x,y);
        elapsed(k) = toc;
    end
    fprintf('[%s] The average elapsed time with %d runs (ms): %.3f\n', input_file, runs, mean(elapsed)*1000);
    disp(elapsed);
    fprintf('Output: n=%d, size=%d\n', n, length(x));
    disp(result(1:10));
end
