<h1 id="escalera-mecánica">Escalera Mecánica</h1>
<h2>Estados: </h2>
<p> La escalera solo puede funcionar en un sentido a la vez, la idea es que cuando una persona se para sobre el sensor de presion en el principio o en el final de la escalera, la escalera empieza a funcionar en la posición opuesta para que la persona que se encuentra en la parte superior pueda bajar o la persona que se encuentra en la parte inferior pueda subir. Mientras esta funcionando se enciende una luz verde que indica esto, y mientras este activa, no puede cambiar la dirección. Cuando se frena, se indica con una luz roja. </p>
<p> Los 5 primeros estados corresponden a los estados en los que puede estar la escalera, mientras que los otros dos pertenecen a las luces </p>
<ul>
<li>
<p>STOP</p>
</li>
<li>
<p>BAJAR</p>
</li>
<li>
<p>SUBIR</p>
</li>
<li>
<p>FINALIZACION BAJADA</p>
</li>
<li>
<p>FINALIZACION SUBIDA</p>
</li>
<li>
<p>ROJO-FRENADO</p>
</li>
<li>
<p>VERDE-FUNCIONANDO</p>
</li>
<li>
</ul>

<h2>Eventos:</h2>
<ul>
<li>
<p> evPresionS1: se activo el sensor superior, una persona quiere bajar</p>
</li>
<li>
<p> evPresionS2: se activo el sensor inferior, una persona quiere subir</p>
</li>
</ul>

<h2> Operaciones:</h2>
<ul>
<li>
<p> opSubir(Action:boolean, Status:boolean): void : indica que la escalera esta subiendo   </p>
</li>
<li>
<p> opBajar(Action:boolean, Status:boolean): void : indica que la escalera esta bajando</p>
</li>
<li>
<p> opStop(Action:boolean, Status:boolean): void : indica que la escalera esta frenada </p>
</li>
<li>
<p> opLuzRoja(Action:boolean, Status:boolean): void : indica que la luz roja esta encendida </p>
</li>
<li>
<p> opLuzVerde(Action:boolean, Status:boolean): void : indica que la luz roja esta apagada</p>
</li>
</ul>


<h2 id="constantes">Constantes</h2>
<ul>
<li>
<p> ON: boolean = true : Activa una funcion</p>
</li>
<li>
<p> OFF: boolean = false : Desactiva una funcion</p>
</li>
<li>
<p> ONoFF:boolean = true : Activa o desactiva una funcion</p>
</li>

<li>
<p> SUBIR: boolean = true : Indica que la escalera tiene que subir</p>
</li>
<li>
<p> BAJAR: boolean = false ; Indica que la escalera  tiene que bajar</p>
</li>
<li>
<p> STOP: boolean = true ; Indica que la escalera  tiene que parar</p>
</li>
</ul>
<h2 >Variables</h2>
<ul>
<li> personas: integer = 1 ; Variable para saber si la persona termino de bajar antes de frenar</li>
</ul>

<h2 >Señales</h2>
<ul>
<li>
<p> siRojo : Activa la luz roja</p>
</li>
<li>
<p> siVerde : Activa la luz verde</p>
</li>
</ul>
<h2 id="capturas-de-los-diagramas">diagramas</h2>

<p><strong><img src="https://github.com/mechanix97/TPs-cursadagrupo01/blob/master/TP1/EscaleraMecanica/EscaleraMecanica.png" alt=""></strong></p>


