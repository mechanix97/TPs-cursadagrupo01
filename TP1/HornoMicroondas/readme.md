<h1 id="Horno Microondas">Panel de control</h1>
<h2 id="estados">Estados</h2>
<p> Los estados se dividen en dos conjuntos. El primero define el modo, el sengundo, el tipo de cocción. Hay tres modos y dos tipos de cocción. Y nuestro sistema se encontrará en un estado de entre los primeros tres y uno de los ultimos dos </p>
<ul>
<li>Modo 0</li>
<li>Modo 1</li>
<li>Modo 2</li>
<li>Stand By</li>
<li>Cocinando</li>
</ul>

<h2 id="eventos">Eventos:</h2>
<ul>
<li>
<p> evModo: ocurre cuando se quiere cambiar de modo</p>
</li>
<li>
<p> evIniciar: ocurre cuando se da lugar a la cocción</p>
</li>
<li>
<p> evParar: ocurre cuando se desea interrumpir la cocción</p>
</li>
<li>
<p> evPuertaAbierta: ocurre cuando se abre la puerta</p>
</li>
</ul>

<h2 id="operaciones">Operaciones:</h2>
<ul>
<li>
<p> opSetModo(Number:integer): void : Setea el modo</p>
</li>
<li>
<p> opCocinar(Number:integer): void : Setea el tipo de cocción</p>
</li>
<li>
<p> opIdle(): void: Espera</p>
</li>

</ul>
<h2 id="constantes">Constantes:</h2>
<ul>
<li>
<p> MODO0: integer = 0 : Define que el modo sea '0'</p>
</li>
<li>
<p> MODO1: integer = 1 : Define que el modo sea '1'</p>
</li>
<li>
<p> MODO2: integer = 2 : Define que el modo sea '2'</p>
</li>
<li>
<p> MODO: integer = 0 : Define que el modo</p>
</li>

</ul>
<h2 id="capturas-de-los-diagramas">Diagrama Yakindu:</h2>
<p><img src="https://github.com/mechanix97/TPs-cursadagrupo01/blob/master/TP1/HornoMicroondas/HornoMicroondas.PNG" alt=""></p>
