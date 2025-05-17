---
layout:     pagina
class:      elenco
title:      Diario di bordo
permalink:  /log/
excerpt:    ""
---

<section class="elenco post">
    {% for post in site.posts %}
        {% if post.tags contains "log" %}
        <div class="log">
            <a class="title" href="{{ post.url }}">
                <h3>{{ post.title }}</h3>
            </a>
            <p class="data">{{ post.date | date_to_string }}</p>
            <p class="desc">{{ post.og_desc }}</p>
            <p class="tag"><label>tag</label> {{ post.tags | sort | join: ", " }}</p>
            <a class="more" href="{{ post.url | relative_url}}">leggi tutto</a>
        </div>
        {% endif %}
    {% endfor %}
</section>
