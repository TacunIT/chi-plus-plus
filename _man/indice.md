---
layout:     manuale
class:      indice
title:      Indice
h1:         Indice
precedente: dedica.html
seguente:   premessa.html
permalink:  /man/indice
no-index:   true
---

# {{ page.h1 }}

<section class="indice">
    {% for capitolo in site.man %}
        {% if capitolo.no-index == null %}
        <h3 {% if capitolo.bozza %}class="bozza"{% endif %} >
            <a href="{{ capitolo.url }}">
                {{ capitolo.title }}
            </a>
        </h3>
        {% endif %}
    {% endfor %}
</section>
