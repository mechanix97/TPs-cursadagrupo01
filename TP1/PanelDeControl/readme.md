<h1 id="panel-de-control">Panel de control</h1>

<h2 id="estados">Estados</h2>
<p> Siempre se encontrará en un estado de entre los primeros tres y uno de los ultimos dos </p>
<ul>
<li>Triangular</li>
<li>Cuadrada</li>
<li>Senoidal</li>
<li>Tension</li>
<li>Frecuencia</li>
</ul>

<h2 id="eventos">Eventos:</h2>
<ul>
<li>
<p> evForma: ocurre cuando se quiere cambiar la forma de la señal</p>
</li>
<li>
<p> evMagnitud: ocurre cuando se quiere cambiar la magnitud</p>
</li>
<li>
<p> evUp: ocurre cuando se quiere incrementar la magnitud (frec o tens)</p>
</li>
<li>
<p> evDown: i ocurre cuando se quiere decrementar la magnitud (frec o tens)</p>
</li>
</ul>

<h2 id="operaciones">Operaciones:</h2>
<ul>
<li>
<p> opSetForma(Number:integer): void : Setea la forma de la señal</p>
</li>
<li>
<p> opSetMagnitud(Number:integer): void : Setea la magnitud de la señal</p>
</li>
<li>
<p> opIncTens(): void: Incrementa la tensión</p>
</li>
<li>
<p> opDecTens(): void : Decrementa la tensión</p>
</li>
<li>
<p> opIncFrec(): void : Incrementa la frecuencia</p>
</li>
<li>
<p> opDecFrec(): void : Decrementa la frecuencia</p>
</li>
</ul>
<h2 id="constantes">Constantes:</h2>
<ul>
<li>
<p> TRIANG: integer = 0 : Define que la forma de la señal es triangular</p>
</li>
<li>
<p> CUADR: integer = 1 : Define que la forma de la señal es cuadrada</p>
</li>
<li>
<p> SENOI: integer = 2 : Define que la forma de la señal es senoidal</p>
</li>
<li>
<p> TENS: integer = 0 : Define que la magnitud es tensión</p>
</li>
<li>
<p> FREC: integer = 1 : Define que la magnitud es freciencia</p>
</li>
</ul>
<h2 id="capturas-de-los-diagramas">Diagrama Yakindu:</h2>
<p><img src="https://github.com/mechanix97/TPs-cursadagrupo01/blob/master/TP1/PanelDeControl/PanelDeControl.PNG" alt=""></p>

<h1> Version con botones </h1>
<p> Se utiliza el boton TEC 1 para cambiar la forma de la señal (triangular, cuadrada o senoidal), segun la forma de la señal cambiaria el led RGB de color. Se utilizan los botones TEC 2 / TEC 3 para disminuir/aumentar la magnitud (frecuencia o tension), cada vez que se presiona se enciende la LED3. Se utiliza el boton TEC4 para elegir entre la magnitud a modificar,  ya sea frecuencia o tension, se enciende la LED1 si es tension y la LED2 si es frecuencia </p>
