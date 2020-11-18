<h1 >Tobillera Electrónica</h1>
<h2>Estados: </h2>
<p> El nodo al conectarse entra al estado de sensado donde realiza la medicion correspondiente, y luego de un segundo pasa al estado para enviar los datos al servidor. En este punto, se chequea si existe conexion a internet, y si es asi, pasa al estado SERVER donde se guardan y muestran los datos. Luego de 1 segundo vuelve al estado anterior, del cual pasará al estado SLEEP ( si se cumple que se envio la informacion). El equipo permanecera en este estado con un clock activado que, luego de cierto tiempo (configurable) volverá al estado de medicion. </p>

<ul>
<li>
<p>MEASURE</p>
</li>
<li>
<p>SEND DATA</p>
</li>
<li>
<p>SLEEP</p>
</li>
<li>
<p>SERVER</p>
</li>
</ul>

<h2>Eventos:</h2>
<ul>
<li>
<p> evSendData: se envia la informacion al servidor</p>
</li>
</ul>

<h2> Operaciones:</h2>
<ul>
<li>
<p> opSetMeasure(): void : indica que entro al estado de medicion </p>
</li>
<li>
<p> opSetSleep(): void : indica que entro al estado de sleep</p>
</li>
<li>
<p> opSendData(): void : indica que entro al estado de envio de datos </p> 
</li>
<li>
<p> opPrintData(): void : indica que entro al estado donde se muestran datos al usuario </p>
</li>
<li>
<p> opCheckInternet(): void : verifica que exista internet para enviar los datos al servidor</p>
</li>
</ul>


<h2 >Constantes:</h2>
<ul>
<li>
<p> TIME_CONFIG: integer = 100 : contador, se setea el tiempo entre mediciones </p>
</li>
</ul>

<h2> Variables:</h2>
<ul>
<li>
<p> t: integer : va decrementando, para saber el tiempo restante antes de la medicion </p>
</li>
<li>
<p> dataUpload:boolean: segun su estado se corrobora si la informacion se subio o no al servidor</p>
</li>
</ul>

<h2>diagrama Yakindu</h2>
<p><strong><img src="https://github.com/mechanix97/TPs-cursadagrupo01/blob/master/TP1/SensadoSuelo/SensadoSuelo.PNG" alt=""></strong></p>

