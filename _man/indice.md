---
status:     pubblicato
layout:     manuale
class:      indice
title:      Indice
h1:         Indice
permalink:  "/man/indice"
---

# {{ page.h1 }}

<section class="indice">
    {% for capitolo in site.man %}
        {% if capitolo.class == 'capitolo' %}
        <div class="capitolo">
            <h3 {% if capitolo.status=='bozza' %}class="bozza"{% endif %} >
                <a href="{{ capitolo.url }}">{{ capitolo.title }}</a>
            </h3>
            <p>{{ capitolo.og_desc }}</p>
        </div>
        {% endif %}
    {% endfor %}
</section>
