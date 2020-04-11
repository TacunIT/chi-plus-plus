---
status:     pubblicato
layout:     manuale
class:      indice
title:      Indice
h1:         Indice
permalink:  /man/indice
---

# {{ page.h1 }}

<section class="indice">
    {% for capitolo in site.man %}
        {% if capitolo.class == 'capitolo' %}
        <h3 {% if capitolo.status=='bozza' %}class="bozza"{% endif %} >
            <a href="{{ capitolo.url }}">{{ capitolo.title }}</a>
            {% if capitolo.status=='redazione' %}
            <img src="https://img.shields.io/badge/stato-in_redazione-orange"  
                 alt="Stato documento: redazione" 
                 class="badge">
            {% endif %}
        </h3>
        {% if capitolo.title == 'Epilogo' %}
        <hr>
        {% endif %}
        {% endif %}
    {% endfor %}
</section>
