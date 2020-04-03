---
layout:     manuale
class:      indice
index:      0
title:      Indice
h1:         Indice
precedente: dedica.html
seguente:   premessa.html
permalink:  /man/indice
---

# {{ page.h1 }}

<section class="indice">
    {% for capitolo in site.man %}
        {% if capitolo.index > 0 %}
        <h3 {% if capitolo.bozza %}class="bozza"{% endif %} >
            <a href="{{ capitolo.url }}">
                {{ capitolo.title }}
            </a>
        </h3>
        {% if capitolo.title == 'Epilogo' %}
        <hr>
        {% endif %}
        {% endif %}
    {% endfor %}
</section>
