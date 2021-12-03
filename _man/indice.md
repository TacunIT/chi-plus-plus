---
class:      indice
layout:     manuale
og_desc:    ""
og_img:     "/assets/img/og-img/indice.jpg"
permalink:  "/man/indice"
status:     pubblicato
title:      Indice
---

# {{ page.title }}

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
