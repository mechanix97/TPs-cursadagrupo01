<h1 id="portón-levadizo">Portón Levadizo</h1>
<h2 >Estados:</h2>
<p>Los primeros 4 son los posibles estados del porton, mientras que los ultimos dos son estados de la señalización luminoza </p>
<ul>
<li>
<p> CERRADO</p>
</li>
<li>
<p> ABIERTO</p>
</li>
<li>
<p> CERRANDO</p>
</li>
<li>
<p> ABRIENDO</p>
</li>
<li>
<p> APAGADA</p>
</li>
<li>
<p> TITILAR</p>
</li>
</ul>


<h2 id="eventos">Eventos:</h2>
<ul>
<li>
<p> evRemoto: Es la indicación de una señal externa que activa el porton</p>
</li>
<li>
<p> evAbrio: indica si el porton termino de abrir</p>
</li>
<li>
<p> evCerro: indica si el porton termino de cerrar</p>
</li>
</ul>

<h2 >Operaciones:</h2>
<ul>
<li>
<p> opMotor(Action:boolean, State:boolean):void : Prende o apaga el motor segun el estado de sus argumentos (la accion y el estado) </p>
</li>
<li>
<p> opLuzRoja(Action:boolean, State:boolean):void : Prende o apaga la luz roja segun el estado de sus argumentos (la accion y el estado)</p>
</li>
<li>
<p> opLuzVerde(Action:boolean, State:boolean):void : Prende o apaga la luz verde segun el estado de sus argumentos (la accion y el estado)</p>
</li>
</ul>

<h2 >Constantes:</h2>
<ul>
<li>
<p> OPEN:boolean = true : Indica que el porton se tiene que abrir</p>
</li>
<li>
<p> CLOSE:boolean = false : Indica que el porton se tiene que cerrar</p>
</li>
<li>
<p> ON:boolean = true : La accion X esta activada </p>
</li>
<li>
<p> OFF:boolean = false : La accion X esta desactivada</p>
</li>
<li>
<p> ONoFF:boolean = true : Prenderá o apagará cierta función.</p>
</li>
<li>
<p> TOGGLE:boolean = false : Para manejar el titilar de la luz roja</p>
</li>
</ul>
<h2 >Señales:</h2>
<ul>
<li>
<p> siTitilar: activa el titilar de la luz roja</p>
</li>
<li>
<p> siNoTitilar : desactiva el titilar de la luz roja</p>
</li>
</ul>
<h2>Diagrama Yakindu:</h2>
<p><img src="https://github.com/mechanix97/TPs-cursadagrupo01/blob/master/TP1/PortonLevadizo/PortonLevadizo.PNG" alt=""></p>
