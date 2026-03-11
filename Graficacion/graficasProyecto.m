% Script para graficar tiempos desde un único archivo .txt
clear; clc;

% 1. Configuración manual
nombre_archivo = 'algoritmo1.txt'; % Nombre del archivo del respectivo algoritmo con todos los bloques

% Valores del eje X (Cantidad de datos 'n').
% IMPORTANTE: Se deben ingresar ingresar tantos valores aquí como bloques de 4 líneas se tengan en el .txt.
n_values = [1000, 2000, 3000, 4000, 5000, 8000, 10000, 50000, 100000, 150000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000, 1500000, 2000000]; 

try
    % 2. Leer todo el contenido del archivo de golpe
    contenido = fileread(nombre_archivo);
    
    % Extraer todos los números del documento (conservando decimales y negativos)
    datos_extraidos = regexp(contenido, '-?\d+\.?\d*', 'match');
    
    % Convertir todo el arreglo de texto a un vector numérico de MATLAB
    todos_los_numeros = str2double(datos_extraidos);
    
    % 3. Validación de seguridad
    % Calculamos cuántos bloques de 4 datos encontró el código
    num_bloques = length(todos_los_numeros) / 4;
    
    if num_bloques ~= length(n_values)
        error('La cantidad de valores en n_values (%d) no coincide con los bloques en el txt (%d).', length(n_values), num_bloques);
    end
    
    % 4. Separar los datos (La magia de la indexación)
    % Sintaxis: vector(inicio : salto : fin)
    t_real = todos_los_numeros(1:4:end); % Inicia en 1, salta de 4 en 4
    t_user = todos_los_numeros(2:4:end); % Inicia en 2, salta de 4 en 4
    t_sys  = todos_los_numeros(3:4:end); % Inicia en 3, salta de 4 en 4
    p_cpu  = todos_los_numeros(4:4:end); % Inicia en 4, salta de 4 en 4
    
    % 5. Generación de Gráficas
    figure('Name', 'Análisis de Rendimiento', 'NumberTitle', 'off');

    % Gráfica 1: Real
    subplot(2, 2, 1);
    plot(n_values, t_real, '-o', 'LineWidth', 1.5, 'Color', 'r', 'MarkerFaceColor', 'r');
    title('Real (Tiempo Total)');
    xlabel('Cantidad de datos (n)'); ylabel('Segundos (s)');
    grid on;

    % Gráfica 2: User
    subplot(2, 2, 2);
    plot(n_values, t_user, '-o', 'LineWidth', 1.5, 'Color', 'b', 'MarkerFaceColor', 'b');
    title('User (Tiempo CPU)');
    xlabel('Cantidad de datos (n)'); ylabel('Segundos (s)');
    grid on;

    % Gráfica 3: Sys
    subplot(2, 2, 3);
    plot(n_values, t_sys, '-o', 'LineWidth', 1.5, 'Color', 'g', 'MarkerFaceColor', 'g');
    title('Sys (Tiempo E/S)');
    xlabel('Cantidad de datos (n)'); ylabel('Segundos (s)');
    grid on;

    % Gráfica 4: CPU/Wall
    subplot(2, 2, 4);
    plot(n_values, p_cpu, '-o', 'LineWidth', 1.5, 'Color', 'm', 'MarkerFaceColor', 'm');
    title('CPU / Wall');
    xlabel('Cantidad de datos (n)'); ylabel('Porcentaje (%)');
    grid on;

    sgtitle('Impacto de la cantidad de datos en el rendimiento');
    
catch ME
    % Si hay un error (archivo no encontrado o vectores no coinciden), lo muestra en rojo
    fprintf(2, 'Hubo un error: %s\n', ME.message);
end