---
layout:     default
class:      log
title:      Zibald-1
permalink:  /zibald-1/
---
<h1>Zibald 1</h1>
<section class="elenco post">
    {% for post in site.posts %}
        {% if post.status == "pubblicato" %}
            <div class="faq">
                <h3>{{ post.title }}</h3>
                {{ post.content }}
            </div>
        {% endif %}
    {% endfor %}
</section>
