---
layout:     manuale
class:      indice
title:      C'hi++ - Il senso della Vita è il debug
h2:         Indice
precedente: dedica.html
seguente:   premessa.html
permalink:  /man/indice
no-index:   true
---

<a class="logo" href="/man/"><img class="logo" alt="C'hi++" title="C'hi plus plus" src="/assets/img/chi-plus-plus.png"></a>
<section class="indice">
    {% for capitolo in site.manuale %}
        {% if capitolo.no-index == null %}
        <h3 {% if capitolo.bozza %}class="bozza"{% endif %} >
            <a href="{{ capitolo.url }}">
                {{ capitolo.h2 }}
            </a>
        </h3>
        {% endif %}
    {% endfor %}
    <h3 class="home">
        <a href="/" title="Torna alla home-page"><i class="fa fa-home fa-2x" aria-hidden="true"></i></a>
    </h3>
</section>
