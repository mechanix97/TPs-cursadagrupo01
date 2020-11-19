<h1 >Sensado del Suelo</h1>
<h2>Estados: </h2>
<ul>
<li>
<p>INITIALIZE</p>
</li>
<li>
<p>MEASURE</p>
</li>
<li>
<p>ALMACENAMIENTO LOCAL</p>
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


<h2>diagrama Yakindu</h2>
<p><strong><img src="https://github.com/mechanix97/TPs-cursadagrupo01/blob/master/TP1/SensadoSuelo/SensadoSuelo.PNG" alt=""></strong></p>

<h2> Explicación de logica y funcionamiento </h2>
<p> Se enciende y queda la placa en el estado inicial, con el LED2 encendido, este estado se puede aprovechar en un futuro para configurar parametros, como por ejemplo, cada cuanto se va a realizar una medición. </p>
<p> Se preciona la tecla TEC1 y se inicia la medición, se enciende una luz verde por 500ms indicando que se esta realizando la medicion (LED RGB). Luego de 1 segundo pasa al estado de almacenamiento local, donde se guarda el valor sensado en una memoria propia y ademas se inicializa el timer. </p>
<p> En este punto, el programa llega a un quiebre, donde segun una condición, optara por tomar un camino o el otro. Se corroborá si hay una conexion a internet: </p>
<p> La tecla TEC2 establece la conexion a internet y enciende el LED1 indicando el exito de la acción, la tecla TEC3, desconecta la placa de internet y apaga la luz </p>

<h3> Si hay conexion a internet </h3>
<p>si la conexión existe, pasa al estado SEND DATA que luego enviara los datos al servidor. Este ultimo se encargará de guardarlos y mostrarlos en pantalla e indicara este procedimento con una led azul prendida por 500ms (LED RGB). Notar que la variable "dataUpload" queda en seteada en TRUE.</p>
<p>Paso Siguiente, una vez que se hayan subido los datos, pasa al estado SLEEP donde permanecera el dispositivo apagado durante un cierto tiempo (configurable) esperando para realizar la nueva medición. Se indica que esta en este estado haciendo titilar el led verde LED3. </p>

<h3> Si no hay internet </h3>
<p>Si no existe la conexión a internet, el sistema pasa directamente al estado SLEEP, en este caso la variable "dataUpload" queda seteada en FALSE. En el estado SLEEP permanecera el dispositivo apagado durante un cierto tiempo (configurable), pero en este caso, cuando el contador termine, intentará enviar nuevamente los datos al servidor y reiniciando el contador.  Se indica que esta en este estado haciendo titilar el led verde LED3.</p>

<p> Finalmente, mientras permanece en el estado sleep, se puede forzar la medición mediante el uso de la tecla TEC4. </p>


 
