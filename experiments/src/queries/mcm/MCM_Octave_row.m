#!/usr/bin/octave-cli

arg_list = argv ();

%% Init
G_DIM_N = str2num(arg_list{1});
G_NUM_UPDATES = str2num(arg_list{2});
G_NUM_RUNS = 3;

G_FLAG_REEVAL = 1;
G_FLAG_INC_DF = 1;
G_FLAG_INC_DBT = 1;

fprintf('--------------------------------\n');
fprintf('CONFIGURATION: row updates N=%d, UPDATES=%d, RUNS=%d\n ', G_DIM_N, G_NUM_UPDATES, G_NUM_RUNS);
fprintf('--------------------------------\n');

%% Initialize timers
G_TIME_REEVAL = zeros(G_NUM_RUNS, 1);
G_TIME_INC_DF = zeros(G_NUM_RUNS, 1);
G_TIME_INC_DBT = zeros(G_NUM_RUNS, 1);

% Input matrices
A1 = rand(G_DIM_N,G_DIM_N);
B2 = rand(G_DIM_N,G_DIM_N);
A3 = rand(G_DIM_N,G_DIM_N);

%% Generate update stream
U = zeros(G_DIM_N, G_NUM_UPDATES);
for j=1:G_NUM_UPDATES
  i = randi(G_DIM_N);
  U(i,j) = 1;
end
U = sparse(U);
V = rand(G_DIM_N, G_NUM_UPDATES);

%% REEVAL
%%%%%%%%%%%%%%%%
if (G_FLAG_REEVAL == 1)

    for tRUN=1:G_NUM_RUNS

        A2 = B2;
        A = zeros(G_DIM_N,G_DIM_N);
        
        tic;
        
        for tCNT_I=1:G_NUM_UPDATES
          A2 = A2 + U(:,tCNT_I) * V(:,tCNT_I)';
          A = A1 * A2 * A3;
        end
       
        G_TIME_REEVAL(tRUN) = toc;
        fprintf('REVAL: %f seconds\n',G_TIME_REEVAL(tRUN));       
    end
end

%% INCR DF
%%%%%%%%%%%%%%%%
if (G_FLAG_INC_DF == 1)

    for tRUN=1:G_NUM_RUNS

        A2 = B2;
        A = zeros(G_DIM_N,G_DIM_N);
        
        tic;
        
        for tCNT_I=1:G_NUM_UPDATES
          u = U(:,tCNT_I);
          v = V(:,tCNT_I);
          A += (A1 * u) * (v' * A3);
          A2 += u * v';
        end
       
        % Log
        G_TIME_INC_DF(tRUN) = toc;
        fprintf('INC_DF: %f seconds\n',G_TIME_INC_DF(tRUN));        
    end
end

%% INCR DBT
%%%%%%%%%%%%%%%%
if (G_FLAG_INC_DBT == 1)

    for tRUN=1:G_NUM_RUNS

        A2 = B2;
        A = zeros(G_DIM_N,G_DIM_N);
        
        tic;
        
        for tCNT_I=1:G_NUM_UPDATES
          u = U(:,tCNT_I);
          v = V(:,tCNT_I);
          dA2 = sparse(u * v');
          A += A1 * dA2 * A3;
          A2 += dA2;
        end
       
        % Log
        G_TIME_INC_DBT(tRUN) = toc;
        fprintf('INC_DBT: %f seconds\n',G_TIME_INC_DBT(tRUN));
    end
end


fprintf('=== REPORT ===\n');
if (G_FLAG_REEVAL == 1) 
    fprintf('(row) REEVAL : u=%f seconds, d=%f,    per update: u=%f seconds, d=%f\n', mean(G_TIME_REEVAL), std(G_TIME_REEVAL), mean(G_TIME_REEVAL/G_NUM_UPDATES), std(G_TIME_REEVAL/G_NUM_UPDATES));
end
if (G_FLAG_INC_DF == 1) 
    fprintf('(row) INC_DF : u=%f seconds, d=%f,    per update: u=%f seconds, d=%f\n', mean(G_TIME_INC_DF), std(G_TIME_INC_DF), mean(G_TIME_INC_DF/G_NUM_UPDATES), std(G_TIME_INC_DF/G_NUM_UPDATES));
end
if (G_FLAG_INC_DBT == 1) 
    fprintf('(row) INC_DBT: u=%f seconds, d=%f,    per update: u=%f seconds, d=%f\n', mean(G_TIME_INC_DBT), std(G_TIME_INC_DBT), mean(G_TIME_INC_DBT/G_NUM_UPDATES), std(G_TIME_INC_DBT/G_NUM_UPDATES));
end

fprintf ('Done\n');
