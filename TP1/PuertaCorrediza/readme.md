<h1 id="puerta-corrediza">Puerta Corrediza</h1>
<h2 >Estados:</h2>
<p>Los estados se dividen en dos conjuntos. El primero refiere a los cuatro estados posibles del porton, el sengundo, a los estados de la señalización luminoza. </p>
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
<p> evPresencia: indica la prensencia de un sujeto frente a la puerta</p>
</li>
<li>
<p> evNoPresencia: indica la usencia de un sujeto frente a la puerta</p>
</li>
<li>
<p> evAbrio: indica si el porton terminó de abrir</p>
</li>
<li>
<p> evCerro: indica si el porton terminó de cerrar</p>
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
<p><img src="https://github.com/mechanix97/TPs-cursadagrupo01/blob/master/TP1/PuertaCorrediza/PuertaCorrediza.PNG" alt=""></p>

<h1> Version con Botones </h1>
<p>El estado inicial es CERRADO, esto se indica mediante una luz Roja prendida (LED RGB) al precionar la tecla TEC 1 simulamos una presencia frente a la purta lo que hara que la puerta se empieze a abrir , el LED3 empezara a titilar indicando esto.  Con la tecla TEC3 indicamos que la puerta ya abrio, por lo que deja de titilar el led y se prende el LED RGB en color verde. Si en este intante se apreta el boton TEC2, indicando que no hay una presencia frente al porton, el porton comienza a cerrarse. Finalmente con la tecla TEC4 indicamos que el porton ya esta cerrrado y se encientde el LEDRGB en rojo. Cabe destacar que en el paso intermedio, es decir, mientras esa abriendo o mientras esta cerrando puede cambiar de accion en funcion si detecta o no una presencia frente a el </p>
