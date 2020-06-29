---
layout:     pagina
class:      elenco
title:      Zibald-1
permalink:  /log/
---

<section class="elenco post">
    {% for post in site.categories.log %}
        <div class="log">
            <a class="more" href="{{ post.url | absolute_url }}">
                <h3>{{ post.title }}</h3>
            </a>
            <p class="data">{{ post.date | date_to_string }}</p>
            {% if post.excerpt != "" %}
                {{ post.excerpt }}
                <a class="more" href="{{ post.url | absolute_url }}">leggi tutto</a>
            {% else %}
                {{ post.content }}
            {% endif %}
        </div>
    {% endfor %}
</section>
